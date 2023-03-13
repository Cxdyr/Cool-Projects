#ifndef FUELCHAMBER_H
#define FUELCHAMBER_H
#include <list>
#include <iostream>
#include <string>
#include <crew.h>
using namespace std;

class fuelchamber
{
    public:
        fuelchamber();
        virtual ~fuelchamber();

        int Getprefuelct() { return prefuelct; }
        void Setprefuelct(int val) { prefuelct = val; }
        int Getincubationtime() { return incubationtime; }
        void Setincubationtime(int val) { incubationtime = val; }
        int Getfuelct() { return fuelct; }
        void Setfuelct(int val) { fuelct = val; }
        int Getcrewct(){return crewct;}
        void Setcrewct(int val){crewct = val;}

        void Display();
        void Incubate();

    private:
        int prefuelct;
        int incubationtime;
        int fuelct;
        int crewct;

};

#endif // FUELCHAMBER_H
