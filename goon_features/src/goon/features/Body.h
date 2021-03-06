#ifndef __GOON_FEATURES_BODY_H
#define __GOON_FEATURES_BODY_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "opencv2/core/core.hpp"

#include "goon/features/ColorBlob.h"

namespace goon 
{
// This class represents a 2D body. 
// It is represented by the following elements: 
// a mask
// a window 
// Extends from ColorBlob
 class Body : public ColorBlob
{
 public:
    static const uchar BODY_VALUE = 255;
    static const uchar BORDER_VALUE = 1;
     
 protected:
     cv::Mat mask;       // body mask
     cv::Rect window;   // body window in image

 public:
    Body();

    cv::Mat& getMask() {return mask;}             
    cv::Rect& getWindow() {return window;};

    // copy constructor (needed for mask)
    Body(const Body& oBody);  
    // assignment operator (needed for mask)
    Body& operator=(const Body& oBody);

    // fills the Body with the given mask and window (cloning the mask)    
    void setMaskAndWindow(cv::Mat& mask, cv::Rect& window);    

    virtual void clear();
    
    void computeMass();
    // compute body basic shape (centroid & covariances)
    void computeBlob();
    // compute body complex shape (shape factor & orientation)    
    void computeShape();
    // compute mask with only the body's border
    cv::Mat computeBorderMask();
    
    // merges with another Body
    virtual void merge(Body& oBody);

    // computes the body's overlapped surface with a given mask (and window)
    int computeOverlap(cv::Mat& maskB, cv::Rect& windowB);

    // computes the body's overlapped surface with another body (the intersection of both masks)
    // the overlapped area (pixels) is returned
    int computeOverlap(Body& oBody);
            
    virtual std::string toString();
    virtual std::string shortDesc();             
    
};  

}  
#endif
