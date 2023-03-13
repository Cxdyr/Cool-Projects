#include "crew.h"

crew::crew()
{
    locationID = 0;
    health = 100;
    hunger = 100;
    happiness = 100;
}

crew::~crew()
{
    //dtor
}

void crew::Display()
{
    string locationstring;
    if(locationID==0){locationstring="main haul";}
    else if(locationID==1){locationstring="ship farm";}
    else if(locationID==2){locationstring="fuel synthesization chamber";}
    else{locationstring = "dead";}
    cout << "crew member " << id << ", location: " << locationstring << ", health: " << health << ", hunger: " << hunger << ", happiness: " << happiness << endl;
}
