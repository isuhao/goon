#ifndef __GOON_VISION_FOCUS_H
#define __GOON_VISION_FOCUS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>
#include <opencv2/core/core.hpp>

#include "goon/core/GoonModule.h"
#include "goon/data/base/roi.h"
#include "tuly/control/module3.h"

namespace goon
{    
// Module in charge of focusing and following the visual target.
class Focus : public GoonModule
{
public:
    // states of Focus module
    enum eState
    {
        eSTATE_SEARCH,
        eSTATE_TRACK,
        eSTATE_LOST
    };
    // search modes
    enum eMode
    {
        eSEARCH_POSITION,
        eSEARCH_COLOR,
        eSEARCH_MOVEMENT,
        eSEARCH_DIM
    };

private:
    static log4cxx::LoggerPtr logger;
    // logic
    int mode;   // search mode
    cv::Vec3f features;    // feature values to be searched 
    int targetROI;      // ID of target ROI

public:
    Focus();
    //~Focus();
        
    // just one loop execution (for testing)
    void oneShot();       

private:
    // show module initialization in logs
    virtual void showInitialized();    
    // first action after thread begins 
    virtual void first();
    // loop inside the module thread 
    virtual void loop();             
    // last action before thread ends
    virtual void bye();
    
    void senseBus();
    void writeBus();
    void showState();
    
    bool selectTarget();
    // try to update the target's info 
    bool followTarget();
    // try to detect a lost target
    bool detectTarget();
    // compute interest value 
    float computeInterest(ROI& oROI);

};

}
#endif