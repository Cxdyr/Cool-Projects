#include "ship.h"

ship::ship()
{
    distance = 0;
    health = 300;
    fuelct = 300;
    foodct = 300;
}

ship::~ship()
{
    //dtor
}

void ship::Display()
{
    cout << "ship health: " << health << ", ship fuel: " << fuelct << ", ship food: " << foodct <<endl;
    cout << "distance traveled: " << distance << " million miles. " <<endl;


    cout << "crew list: \n";
    citr = crewlist.begin();
    while(citr!=crewlist.end())
    {
        (*citr)->Display();
        citr++;
    }
}

void ship::FeedCrew()
{
    cout << "how much would you like to feed each crew member: ";
    int val;
    cin >> val;
    int crewsize = crewlist.size();
    int attemptfeed = val*crewsize;
    if(attemptfeed>foodct){cout << "we do not have the resources to feed our crew this much..." <<endl;}
    else
    {
        foodct = foodct-attemptfeed;
        citr = crewlist.begin();
        while(citr!=crewlist.end())
        {
            if((*citr)->GetlocationID()!=3)
            {
            (*citr)->Sethunger((*citr)->Gethunger()+val);
            }
            citr++;
        }

    }
}

void ship::WatchMovie()
{
    citr = crewlist.begin();
    while(citr!=crewlist.end())
    {
        if((*citr)->GetlocationID()!=3)
        {
        (*citr)->Sethappiness((*citr)->Gethappiness()+6);
        }
        citr++;
    }
}

bool ship::CheckCrew()
{
    int ctr = 0;
    citr = crewlist.begin();
    while(citr!=crewlist.end())
    {
        if((*citr)->GetlocationID()!=3)
        {
            ctr++;
        }
        citr++;
    }

    if(ctr>0 && health>0 && fuelct >0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
