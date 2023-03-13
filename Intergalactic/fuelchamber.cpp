#include "fuelchamber.h"

fuelchamber::fuelchamber()
{
    prefuelct = 0;
    fuelct = 0;
    incubationtime = 0;
}

fuelchamber::~fuelchamber()
{
    //dtor
}

void fuelchamber::Display()
{
    cout << "crew amount: " << crewct << ", prefuel amount: " << prefuelct << ", fuel amount: " << fuelct << ", remaining time: " << incubationtime << endl;
}

void fuelchamber::Incubate()
{
    incubationtime--;
    if(incubationtime<=0)
    {
        incubationtime=0;
        fuelct = fuelct + prefuelct;
        prefuelct =0;
    }
}
