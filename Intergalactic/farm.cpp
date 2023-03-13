#include "farm.h"

farm::farm()
{
    seedct = 0;
    foodct = 0;
    incubationtime = 0;
}

farm::~farm()
{
    //dtor
}

void farm::Display()
{
    cout << "crew amount: " << crewct << ", seed amount: " << seedct  << ", food amount: " << foodct << ", remaining time: " << incubationtime << endl;
}

void farm::Incubate()
{
    incubationtime--;
    if(incubationtime<=0)
    {
        incubationtime=0;
        foodct = foodct+seedct;
        seedct = 0;
    }
}
