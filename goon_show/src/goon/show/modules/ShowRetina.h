#ifndef __GOON_SHOW_SHOWRETINA_H
#define __GOON_SHOW_SHOWRETINA_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include <opencv2/opencv.hpp>

#include "goon/core/GoonModule.h"
#include "goon/data/retina.h"
#include "goon/data/rois.h"
#include "goon/data/cortex/Object.h"
#include "goon/show/monitor/RetinaMonitor.h"
#include "goon/show/monitor/ROIsMonitor.h"
#include "goon/show/monitor/RetinaSaver.h"
#include "tron2/tivy/DualWindow.h"

namespace goon
{
// Monitoring module of the goon vision process
class ShowRetina: public GoonModule
{
private:
    static log4cxx::LoggerPtr logger;
    // logic
    cv::Mat imageCam;
    cv::Mat imageRetina;
    cv::Mat imageROIs;
    RetinaMonitor oRetinaMonitor;
    ROIsMonitor oROIsMonitor;
    tron2::DualWindow oDualWindow; 
    std::string windowName;
    Retina oRetina3;
    Rois oROIs3;
    Object oObject3;
    int grabBeat;       // Grab module's beat
    int seeBeat;        // See module's beat
    int lookBeat;        // Look module's beat
    
public:
    ShowRetina();
    ~ShowRetina();

    // just one loop exectution (for testing)
    void oneShot();

private:
    // show module initialization in logs
    virtual void showInitialized();        
    // first action after thread begins 
    virtual void first();
    // loops inside the thread 
    virtual void loop();            
    // last action before thread ends
    virtual void bye();    

    // waits till there's a valid image in the shared visual data (used for retinal vision size initialization)
    void wait4FirstCapture();
    
};

}
#endif
