#include "person.h"
#include <iostream>
#include <string>

using namespace std;
person::person(int n)
{
    status = 0;
    statusclock = 0;
}

person::~person()
{
    //dtor
}

void person::Display()
{
    string statusString;
    if(status==0)
    {
        statusString = "negative";
    }
    else if(status==1)
    {
        statusString = "exposed";
    }
    else if(status==2)
    {
        statusString= "infected";
    }
    else if(status==3)
    {
        statusString=" symptomatic";
    }
    else if(status==4)
    {
        statusString="dead";
    }

    cout << "person id: " << id << ", age: " <<age << "  status: " << statusString << endl;
}

int person::groupsize()
{
    int groupam = groupids.size();
    return groupam;
}

int person::getgroup1()
{
    int id1 = groupids.back();
    return id1;

}
int person::getgroup2()
{
   int id3 = groupids.front();
   return id3;

}





