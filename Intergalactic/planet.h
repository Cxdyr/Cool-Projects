#ifndef PLANET_H
#define PLANET_H
#include <random>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class planet
{
    public:
        planet();
        virtual ~planet();

        string Getname(){return name;}
        void Setname(string val){name = val;}
        double Getgravity() { return gravity; }
        void Setgravity(double val) { gravity = val; }
        int GetsurvivableAt() { return survivableAt; }
        void SetsurvivableAt(int val) { survivableAt = val; }
        int GetwaterSigns() { return waterSigns; }
        void SetwaterSigns(int val) { waterSigns = val; }
        int GetsoilSigns() { return soilSigns; }
        void SetsoilSigns(int val) { soilSigns = val; }
        int Getoversurv() { return oversurv; }
        void Setoversurv(int val) { oversurv = val; }

        void Display();


    private:
        string name;
        double gravity;
        int survivableAt;
        int waterSigns;
        int soilSigns;
        int oversurv;
};

#endif // PLANET_H
