/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdlib.h>
#include <opencv2/highgui/highgui.hpp>

#include "goon/monitor/RetinaSaver.h"

namespace goon 
{
RetinaSaver::RetinaSaver()
{
    path = std::getenv("HOME");    
    imgExtension = ".jpg";
}

void RetinaSaver::setDestinationFolder(std::string path)
{
    this->path = path;            
}

void RetinaSaver::saveRegions (cv::Mat& image_cam, std::vector<Region>& listRegions)
{    
    oDraw.setSize(image_cam);
    
    // draw each segmented region in a separate file
    for (Region& oRegion: listRegions) 
    {
        // skip simple regions
        if (oRegion.getType() == Region::eREG_SIMPLE)
            continue;
        
        oDraw.clearBackGround();
        // draw masks
        oDraw.setExactColor(oRegion.getRGB());
        oDraw.drawMask (oRegion.getMat(), oRegion.getWindow2());
        oDraw.drawWindow (oRegion.getWindow2());

        // draw centroids
        int* pos = oRegion.getPos();
        cv::Point centroid(pos[0], pos[1]);                        
        int color;
        switch (oRegion.getType())
        {
            case Region::eREG_SIMPLE:
                color = Draw::eGREEN;
                break;
            case Region::eREG_MERGED:
                color = Draw::eRED;
                break;
            case Region::eREG_COLLECTION:
                color = Draw::eYELLOW;
                break;
        }
        oDraw.drawPoint(centroid, Draw::eRED, 3);

        // draw ID's
        oDraw.drawNumber(oRegion.getID(), centroid);                        

        // save file        
        std::string fileName = path + "/region_" + std::to_string(oRegion.getID()) + imgExtension;
        cv::imwrite(fileName, oDraw.getOutput()); 

//      cv::Point& seed = oRegion.getSeed();
//      oDrawRet.drawPoint(seed, Draw::eYELLOW);
    }
}

}