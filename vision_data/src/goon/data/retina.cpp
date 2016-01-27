/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "goon/data/retina.h"

namespace goon 
{
Retina::Retina ()
{
    ID = -1;
}

Retina::~Retina()
{
    clear();
}
        
int Retina::getID()
{
    std::lock_guard<std::mutex> locker(mutex);
    return ID;    
}

void Retina::setID(int id)
{
    std::lock_guard<std::mutex> locker(mutex);
    ID = id;    
}

std::vector<Region>& Retina::getListRegions() 
{
    std::lock_guard<std::mutex> locker(mutex);
    return listRegions;
};

void Retina::addRegion(Region& oRegion)
{
    std::lock_guard<std::mutex> locker(mutex);
    ID++;
    oRegion.setID(ID);
    listRegions.push_back(oRegion);
}  

// returns a reference to the list of final region IDs        
std::vector<int>& Retina::getListFinalIDs()
{
    std::lock_guard<std::mutex> locker(mutex);
    return listFinalIDs;
};

void Retina::setListFinalIDs(std::vector<int>& listFinalIDs)
{
    std::lock_guard<std::mutex> locker(mutex);
    this->listFinalIDs = listFinalIDs;
}

void Retina::buildListFinalIDs()
{
    std::lock_guard<std::mutex> locker(mutex);
    std::vector<Region>::iterator it_region = listRegions.begin();

    // copies all unmerged regions to the final regions list
    while (it_region != listRegions.end())
    {            
        if (it_region->getType() != Region::eREG_MERGED)
                listFinalIDs.push_back(it_region->getID());        
     
        it_region++;
    }
}

int Retina::getNumRegions()  
{
   std::lock_guard<std::mutex> locker(mutex);
   return listRegions.size();
};

int Retina::getNumFinalIDs()  
{
   std::lock_guard<std::mutex> locker(mutex);
   return listFinalIDs.size();
};

void Retina::clear()
{  
    std::lock_guard<std::mutex> locker(mutex);
    listRegions.clear();
    listFinalIDs.clear();    
    ID = -1;    // first region ID is 0
}
   
Region& Retina::getRegion(int ID)
{
    std::lock_guard<std::mutex> locker(mutex);
    return listRegions.at(ID);    
}
        
// clones this retina into the given one   
void Retina::cloneTo(Retina& oRetina2)
{
    std::lock_guard<std::mutex> locker(mutex);
    // clear the destination retina
    oRetina2.clear();

    Region oRegion2;
    // clones all regions and adds them to the destination retina
    for (Region& oRegion: listRegions) 
    {
        oRegion.cloneTo(oRegion2);
        oRetina2.addRegion(oRegion2);
    }

    // copies the IDs list
    oRetina2.setListFinalIDs(listFinalIDs);
    oRetina2.setID(ID);    
}

}
