#include "planet.h"

planet::planet()
{
    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));
    uniform_int_distribution<int> Watergen(1,5);
    uniform_int_distribution<int> Soilgen(1,4);
    uniform_int_distribution<int> Atmospheregen(1,4);
    uniform_real_distribution<double> Gravgen(1,20);
    int waterval, soilval, atmosval;
    double gravval;
    waterval = Watergen(*gptr);
    soilval = Soilgen(*gptr);
    atmosval = Atmospheregen(*gptr);
    gravval = Gravgen(*gptr);

    name = "unknown";
    gravity = gravval;
    if(waterval==1){waterSigns=1;}
    else{waterSigns=0;}
    if(soilval==1){soilSigns=1;}
    else{soilSigns=0;}
    if(atmosval==1){survivableAt=1;}
    else{survivableAt=0;}

    if(survivableAt==1 && waterSigns==1 && soilSigns==1)
    {
        oversurv = 1;
    }
    else
    {
        oversurv =0;
    }

}

planet::~planet()
{
    //dtor
}

void planet::Display()
{
    string textval;
    if(survivableAt==1 && waterSigns==1 && soilSigns==1){textval = "survivable";}
    else{textval= "unsurvivable";}
    cout << "planet name: " << name << ", gravity: " << gravity << "m/s^2, " << textval << ", atmos " << survivableAt << ", water " << waterSigns << ", soil " << soilSigns << endl;

}
