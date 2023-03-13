#ifndef SHIP_H
#define SHIP_H
#include <list>
#include <iostream>
#include "crew.h"

class ship
{
    public:
        ship();
        virtual ~ship();

        int Gethealth() { return health; }
        void Sethealth(int val) { health = val; }
        int Getfoodct() { return foodct; }
        void Setfoodct(int val) { foodct = val; }
        int Getfuelct() { return fuelct; }
        void Setfuelct(int val) { fuelct = val; }
        int Getdistance() { return distance; }
        void Setdistance(int val) { distance = val; }
        void addcrew(crew * cptr){crewlist.push_back(cptr);}

        void Display();
        void FeedCrew();
        void WatchMovie();
        bool CheckCrew();


    private:
        int health;
        int foodct;
        int fuelct;
        int distance;
        list<crew*>crewlist;
        list<crew*>::iterator citr;
};

#endif // SHIP_H
