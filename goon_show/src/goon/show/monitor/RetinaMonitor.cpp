/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "goon/show/monitor/RetinaMonitor.h"

using namespace log4cxx;

namespace goon 
{
LoggerPtr RetinaMonitor::logger(Logger::getLogger("goon.show"));

void RetinaMonitor::drawRegions (cv::Mat& image_cam, std::list<Region>& listRegions)
{    
    std::list<Region>::iterator it_region = listRegions.begin();
    std::list<Region>::iterator it_end = listRegions.end();

    oDraw.setSize(image_cam);
    oDraw.clearBackGround();
    
    // walk the list of regions (merged ones are invalid)
    while (it_region != it_end)
    {
        // ignore merged regions
        if (it_region->getType() != Region::eREG_MERGED) 
        //if (it_region->getType() == Region::eREG_COLLECTION) 
        {  
            // draw masks
            oDraw.setExactColor(it_region->getRGB());
            oDraw.drawMask (it_region->getMask(), it_region->getWindow());
            // draw centroids
            cv::Vec2i& pos = it_region->getPos();
            cv::Point centroid(pos[0], pos[1]);            
            if (it_region->is2Merge())
                oDraw.drawPoint(centroid, tivy::Draw::eRED, 3);
            else
                oDraw.drawPoint(centroid);
            // draw ID's
//            int ID = it_region->getID();
//            oDrawRet.drawNumber(ID, centroid);                        
                        
//            cv::Point& seed = it_region->getSeed();
//            oDrawRet.drawPoint(seed, tivy::Draw::eYELLOW);
        }
        it_region++;
    }
}


void RetinaMonitor::drawObject(cv::Mat& image_cam, Object& oObject)
{        
    oDraw.setDefaultColor(tivy::Draw::eYELLOW);
    oDraw.drawWindow(oObject.getWindow());
}

/*
void RetinaMonitor::getBorderMask(cv::Mat& mask, cv::Mat& mask_border)
{
    cv::Mat mask_clean;
    cv::Mat mask_inside;
    
//    cv::threshold(mask_close, mask_body, 2.0, 255, cv::THRESH_BINARY);

    cv::Mat element = cv::getStructuringElement( cv::MORPH_RECT, cv::Size( 3, 3), cv::Point(1, 1));

    // close -> cleans holes 
    cv::morphologyEx(mask, mask_clean, cv::MORPH_CLOSE, element);

    // gradient -> takes border
    //cv::morphologyEx(mask_clean, mask_border, cv::MORPH_GRADIENT, element);

    // erode -> inside body
    cv::erode(mask_clean, mask_inside, element);
    
    mask_border = mask_clean - mask_inside;
}
*/
}