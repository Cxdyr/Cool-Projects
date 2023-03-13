#ifndef FARM_H
#define FARM_H
#include <list>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <crew.h>

using namespace std;

class farm
{
    public:
        farm();
        virtual ~farm();

        int Getseedct() { return seedct; }
        void Setseedct(int val) { seedct = val; }
        int Getincubationtime() { return incubationtime; }
        void Setincubationtime(int val) { incubationtime = val; }
        int Getfoodct() { return foodct; }
        void Setfoodct(int val) { foodct = val; }
        int Getcrewct(){return crewct;}
        void Setcrewct(int val){crewct = val;}

        void Display();
        void Incubate();


    private:
        int seedct;
        int incubationtime;
        int foodct;
        int crewct;
};

#endif // FARM_H
