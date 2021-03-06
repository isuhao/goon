/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>
#include "log4cxx/ndc.h"

#include "goon/show/modules/ShowRetina.h"
#include "goon/show/monitor/RetinaSaver.h"
#include "tron/util/Environment.h"

namespace goon
{  
log4cxx::LoggerPtr ShowRetina::logger(log4cxx::Logger::getLogger("goon.show"));

ShowRetina::ShowRetina() 
{
    modName = "ShowRetina";
    windowName = "Retina";
}

ShowRetina::~ShowRetina() 
{
}

void ShowRetina::showInitialized()
{
    LOG4CXX_INFO(logger, "ShowRetina initialized");             
};

void ShowRetina::first()
{ 
    log4cxx::NDC::push("ShowRetina");   	
    LOG4CXX_INFO(logger, "started");  

    cv::namedWindow(windowName);         

    // set sizes for image show
    wait4FirstCapture();
    pVisualData->getCameraFrameCopy(imageCam);
    imageRetina = imageCam.clone();
    imageROIs = imageCam.clone();
    oDualWindow.resize(imageCam.cols, imageCam.rows);

    // reset beats
    grabBeat = 0;
    seeBeat = 0;
    lookBeat = 0;
}

void ShowRetina::bye()
{
    LOG4CXX_INFO(logger, "ended");     
}

void ShowRetina::loop()
{
    //LOG4CXX_DEBUG(logger, "iteration " << i);                

    // if no new capture (grab beat not changed), skip
    if (pGoonBus->getSO_GRAB_BEAT().getValue() == grabBeat)
        return;        
    // if new capture, get it
    else
    {
        pVisualData->getCameraFrameCopy(imageCam);
        grabBeat = pGoonBus->getSO_GRAB_BEAT().getValue();
    }
    
    // if new See beat update output
    if (pGoonBus->getSO_SEE_BEAT().getValue() != seeBeat)
    {
        seeBeat = pGoonBus->getSO_SEE_BEAT().getValue();       
        
        // get updated copy of retina & rois
        pVisualData->getRetinaCopy(oRetina3);
        pVisualData->getROIsCopy(oROIs3);
        
        // draw regions obtained by the retinal vision 
        oRetinaMonitor.drawRegions(imageCam, oRetina3.getListRegions());            
        oRetinaMonitor.drawObject(imageCam, oObject3);
        imageRetina = oRetinaMonitor.getOutput();
        
        // draw ROIs obtained by the peripheral vision 
        int focusedROI = pGoonBus->getSO_FOCUS_ROI().getValue();
        oROIsMonitor.drawRois(imageCam, oROIs3.getList(), focusedROI);                
        oROIsMonitor.drawFPS(pGoonBus->getSO_SEE_FPS().getValue());
        imageROIs = oROIsMonitor.getOutput();                                

        oDualWindow.setImageLeft(imageROIs);
        oDualWindow.setImageRight(imageRetina);
    }            

    if (pGoonBus->getSO_LOOK_BEAT().getValue() != lookBeat)
    {
        lookBeat = pGoonBus->getSO_LOOK_BEAT().getValue();
        
        // get updated copy of looked object
        pVisualData->getObjectCopy(oObject3);
    }
    
    
    // show dual window
    cv::imshow(windowName, oDualWindow.getImage());   
    cv::waitKey(10);            
}

void ShowRetina::wait4FirstCapture()
{
    LOG4CXX_INFO(logger, "waiting for first image");     
    // wait for new grabbed frame (50ms waits)
    while (pGoonBus->getSO_GRAB_BEAT().getValue() == 0)            
        usleep(50000);
}


// just one loop exectution (for testing)
void ShowRetina::oneShot()
{
    first();
    loop();    
    // show dual window
    cv::imshow(windowName, oDualWindow.getImage());   
    cv::waitKey(-1);            
    bye();
    
    // finally save individual images of retinal regions 
    std::string folder = tron::Environment::getHomePath() + "/TESTS/VISION";    

    // clean folder
    tron::Environment::cleanFolder(folder);
    // save region images
    RetinaSaver oRetinaSaver;
    oRetinaSaver.setDestinationFolder(folder);           
    oRetinaSaver.saveRegions(imageCam, oRetina3.getListRegions(), true);
}

}
