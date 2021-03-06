#ifndef __GOON_PERIPHERAL_ROIS_DETECTION_H
#define __GOON_PERIPHERAL_ROIS_DETECTION_H

/***************************************************************************
 *   Copyright (C) 2011 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <list>
#include <vector>
#include <log4cxx/logger.h>
#include "opencv2/core/core.hpp"

#include "goon/data/retina.h"
#include "goon/data/rois.h"
#include <goon/data/base/roi.h>
#include <goon/data/base/region.h>
#include "goon/features/color/hsv_color.h"


namespace goon
{
// Module for the detection of ROIs, regions of interest that represent physical regions in the scene.
// ROIS are associated to segmented regions, but are living entities with an own history and movement.
class RoisDetection
{
// structure to handle ROI-Region matchings
struct st_match
{
    int roiID;
    int regionID;
    float confidence;    
};    

private:
    static log4cxx::LoggerPtr logger;
    // param
    float minOverlapFraction; // minimum ROI overlap (fraction) required to consider a positive matching
    // vars
    Retina* pRetina;        // pointer to retina
    Rois* pROIs;            // pointer to ROIs
    int eliminations;
    HSVColor oHSVColor;
    cv::Mat matOverlaps;    // matrix of ROI overlaps (ROIS x regions), stores overlap amounts (in pixels) 
    std::vector<st_match> listMatches;  // list of ROI-Region matchings 
    //std::vector<cv::Vec2i> listMatches2; // list of ROI-Region matchings (roi ID, region ID)     

public:
    RoisDetection();
    ~RoisDetection ();

    void detectROIs(Retina& oRetina, Rois& oROIs, int millis);
    
    void setMinOverlapFraction(float value) {minOverlapFraction = value;};

    int getEliminations() {return eliminations;};

private:
    // prepare ROIs for a new detection process
    void prepareDetection();
    
    // try to match ROIs and regions (based on color & overlap)
    void matchROIs2Regions();
    //void matchROIs2Regions2();
    
    // update matched ROIs to follow their regions
    void updateMatchedROIs(int millis);
    //void updateMatchedROIs2(int millis);
    
    // Checks how the given ROI responds to regions. 
    // The number of positive responses is returned
    int compareROI2Regions(int row, ROI& oROI, std::list<Region>& listRegions);
    
    // Establishes correspondences between ROIs and regions
    void findBestMatches();
    // adds a new match to the list of matches
    void newMatch(int roiID, int regionID, float confidence);
    
    // create new ROIs for unmatched regions
    void handleOrphanRegions();
    // adds a new ROI to the list of ROIs
    void newROI(Region& oRegion);
};

}  

#endif
