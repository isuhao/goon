#ifndef __GOON_CORTEX_MODELING_H
#define __GOON_CORTEX_MODELING_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
	
#include <log4cxx/logger.h>
#include <opencv2/core/core.hpp>

#include "goon/data/cortex/Model.h"
#include "goon/data/cortex/Object.h"
#include "goon/data/cortex/ObjectModel.h"
#include "goon/features/Body.h"

namespace goon
{
class Modeling
{
private:
    static log4cxx::LoggerPtr logger;
    // params
    int refWidth;       // reference window width 
    int refMass;       // reference object mass
    // logic
    cv::Point trans;
    float scaling;
    float normalization;
    
public:
    Modeling();
    //~Modeling();

    void modelObject(Object& oObject, ObjectModel& oObjectModel);

private:
    void modelBody(Body& oBody, Model& oModel);
};
}
#endif
