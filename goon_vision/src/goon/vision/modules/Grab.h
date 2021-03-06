#ifndef __GOON_VISION_GRAB_H
#define __GOON_VISION_GRAB_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "goon/core/GoonModule.h"
#include "goon/camera/Grabber.h"

namespace goon
{    
// Module in charge of capturing images from the camera
class Grab : public GoonModule
{
public:
    // states of Grabber module
    enum eState
    {
        eSTATE_ON
    };
    // images source
    enum eSource
    {
        eCAM_WEBCAM,
        eCAM_IPCAM,
        eCAM_WIFIBOT_WIRELESS,
        eCAM_ALBARRACIN,
        eCAM_SOUTHERN_BEACH,
        eVIDEO_CAMPUS_HALL,
        eIMAGE_CAMPUS_HALL1,
        eIMAGE_CAMPUS_HALL2,
        eIMAGE_CAMPUS_HALL3,
        eIMAGE_CAMPUS_HALL4,
        eIMAGE_BABOON,
        eIMAGE_FRUITS,
        eIMAGE_JLUIS,
        eIMAGE_ORANGE1,
        eIMAGE_ORANGE2,
        eIMAGE_ORANGE3,
        eOPTIONS_DIM
    };

private:
    static log4cxx::LoggerPtr logger;
    Grabber oGrabber;   // utility class used for frame grabbing from any source

public:
    Grab();
    //~Grab();
    
    bool setCameraSource(int sourceCamera);   
       
private:
    // show module initialization in logs
    virtual void showInitialized();    
    // first action after thread begins 
    virtual void first();
    // loop inside the module thread 
    virtual void loop();             
    // last action before thread ends
    virtual void bye();
    
    void connect2Camera(int option);
};

}
#endif
