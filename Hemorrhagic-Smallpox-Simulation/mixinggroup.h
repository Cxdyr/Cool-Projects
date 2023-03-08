#ifndef MIXINGGROUP_H
#define MIXINGGROUP_H
#include "person.h"
#include <list>
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

class mixinggroup
{
public:
    mixinggroup(int n);
    virtual ~mixinggroup();

    int Getgid()
    {
        return gid;
    }
    void Setgid(int val)
    {
        gid = val;
    }
    void addperson(person *pptr)
    {
        personlist.push_back(pptr);
    }
    void cleanUp()
    {
        personlist.unique();
    }


    int expoCt();
    int infectct();
    int symtpct();
    int deadct();


    void transmisionDay();
    double probabilityPerson();

    void infectgroup()
    {
        itr=personlist.begin();
        while(itr!=personlist.end())
        {
            (*itr)->Setstatus(2);
            itr++;
        }
    }
    void Display()
    {
        cout << "mixing group " << gid << ", members: " << endl;
        itr=personlist.begin();
        while(itr!=personlist.end())
        {
            (*itr)->Display();
            itr++;
        }
    }

private:
    int gid;
    list<person*> personlist;
    list<person*>::iterator itr;

};

#endif // MIXINGGROUP_H
