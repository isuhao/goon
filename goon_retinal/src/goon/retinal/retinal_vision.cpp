/***************************************************************************
 *   Copyright (C) 2010 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "opencv2/imgproc/imgproc.hpp"          // for cvtColor

#include "goon/retinal/retinal_vision.h"
#include <goon/data/goon_version.h>
#include <goon/data/base/region.h>
#include <goon/features/color/rgb_color.h>
#include <goon/features/shape/shape.h>

using namespace log4cxx;

namespace goon
{
LoggerPtr RetinalVision::logger(Logger::getLogger("goon.retinal"));


RetinalVision::RetinalVision()
{  
    LOG4CXX_INFO(logger, "goon " << GOON_VERSION << " - Retinal vision");
    pRetina = 0;
}

RetinalVision::~RetinalVision()
{
}

void RetinalVision::init(Retina& oRetina, int img_w, int img_h)
{
    pRetina = &oRetina;
    oSegmentation4.init(oRetina, img_w, img_h);
}

// This function changes main parameters of the retinal vision system.
void RetinalVision::setParameters (int retinal_samples, int same_RGB, int similar_RGB)
{
    oSegmentation4.setNumSamples(retinal_samples);
    RGBColor::setTolerances(same_RGB, similar_RGB);
}


// This function performs the retinal vision process. 
// Detects homogenous color regions in the captured image (later used by higher vision processes).
void RetinalVision::update (cv::Mat& image_cam)
{
    LOG4CXX_TRACE(logger, "update - init");

    pRetina->clear();
    
    // convert to HSV space
    cv::Mat image_hsv;        
    cv::cvtColor(image_cam, image_hsv, CV_BGR2HSV);

    oSegmentation4.extractRegions(image_cam, image_hsv);

    oMerge.doMerge(*pRetina);

    pRetina->removeInvalidRegions();

    //LOG4CXX_DEBUG(logger, "final regions = " << mRetina.getNumFinalIDs());
    //describeRegions();
    LOG4CXX_TRACE(logger, "update - end");
}


void RetinalVision::computeCovariances()
{    
    LOG4CXX_DEBUG(logger, "compute shapes ...");

    // walk the list of final regions
    for (Region& oRegion : pRetina->getListRegions())
    {
        LOG4CXX_TRACE(logger, "region = " << oRegion.toString());
        
        Shape::computeCovariances(oRegion.getMask(), oRegion.getWindow(), oRegion.getPos(), oRegion.getCovariances());
    }    
}

void RetinalVision::describeRegions()
{
    LOG4CXX_DEBUG(logger, "regions description ...");
    for (Region& oRegion : pRetina->getListRegions()) 
    {
        LOG4CXX_DEBUG(logger, oRegion.shortDesc());
    } 
}

}