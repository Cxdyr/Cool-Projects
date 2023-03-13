#ifndef CREW_H
#define CREW_H
#include <string>
#include <iostream>
using namespace std;
class crew
{
    public:
        crew();
        virtual ~crew();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        int GetlocationID() { return locationID; }
        void SetlocationID(int val) { locationID = val; }
        int Gethealth() { return health; }
        void Sethealth(int val) { health = val; }
        int Gethunger() { return hunger; }
        void Sethunger(int val) { hunger = val; }
        int Gethappiness() { return happiness; }
        void Sethappiness(int val) { happiness = val; }
        void Display();

    private:
        int id;
        int locationID;
        int health;
        int hunger;
        int happiness;
};

#endif // CREW_H
