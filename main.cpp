#include <cmath>
#include<fstream>
#include "mixinggroup.h"
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    default_random_engine*gptr;
    gptr = new default_random_engine(time(NULL));

    uniform_int_distribution<int>familymembam(0,6); // amount of fam members in each fam
    uniform_int_distribution<int>personage(1,76); // age of normal fam members
    uniform_int_distribution<int>adultage(18,76); // age of the start of each family

    uniform_int_distribution<int>Eschoolchoice(1,8); /// ages 5 -10    we assume under 5 years old are just home schooled or something
    uniform_int_distribution<int>Mschoolchoice(9,12);/// 11 - 13 ages  1= school 1, 2= school2, etc...
    uniform_int_distribution<int>Hschoolchoice(13,14); /// 1 = highschool 1, 2 = highschool 2     ages 14 - 18
    uniform_int_distribution<int>Cchance(1,2); /// 1/2 chance of someone who is 19-21 going to college
    uniform_int_distribution<int>HospitalChance(1,26); /// chance of someone going to hospital

    uniform_int_distribution<int>InfectSympDist(7,15);
    uniform_real_distribution<double>infectDis(0,1);




    mixinggroup * newGroup;
    list<mixinggroup>allmixgroups;
    list<mixinggroup>::iterator mitr;

    int familysize;
    int firstadultage;
    int regAge;
    int personID = 1;
    int familyID = 17;

    person * newPerson;
    list<person*>personlist;
    list<person*>::iterator itr;

    cout << "What size population would you like to create? ";
    int sizepop;
    cin >> sizepop;

    int eSchool, mSchool, hSchool, college, hospitalC;

    for(int i=1; i<=16; i++) ///creates the first 16 mixing groups and adds them to list of mixing groups setting ids too , 1-15 schools, 16 hospital,
    {

        newGroup = new mixinggroup(i);
        newGroup->Setgid(i);

        allmixgroups.push_back(*newGroup);


    }


    while(personlist.size()<sizepop) ///creates whatever amount of people needs and also creates mixing groups 16 through whatever is required. Adds people to list of people in main, and to the
        ///respected mixing groups while adding to the original 15 mixing groups as needed based on age and chance
    {

        newGroup = new mixinggroup(familyID);
        newGroup->Setgid(familyID);

        firstadultage = adultage(*gptr);
        familysize = familymembam(*gptr);

        newPerson = new person(personID);
        newPerson->Setid(personID);
        newPerson->Setage(firstadultage);
        newPerson->addgroup(familyID);
        personlist.push_back(newPerson);
        newGroup->addperson(newPerson);
        newPerson=NULL;
        personID++;

        for(int i=0; i<familysize; i++)
        {
            regAge = personage(*gptr);
            newPerson = new person(personID);
            newPerson->Setid(personID);
            newPerson->Setage(regAge);
            newPerson->addgroup(familyID);
            newGroup->addperson(newPerson);

            ///college chance
            college = Cchance(*gptr);
            hospitalC = HospitalChance(*gptr);

            if(regAge>=5 && regAge<=10)
            {
                eSchool = Eschoolchoice(*gptr);
                mitr=allmixgroups.begin();
                while((*mitr).Getgid()!=eSchool)
                {
                    mitr++;
                }
                newPerson->addgroup(eSchool);
                (*mitr).addperson(newPerson);  /// person who was added to family is a child, needs to be added to an elementary school


            }
            else if(regAge>10 && regAge<15)  ///person added to middle schools
            {
                mSchool = Mschoolchoice(*gptr);
                mitr=allmixgroups.begin();
                while((*mitr).Getgid()!=mSchool)
                {
                    mitr++;
                }
                newPerson->addgroup(mSchool);
                (*mitr).addperson(newPerson);



            }
            else if(regAge>14&& regAge<17) /// person added to highshcools
            {
                hSchool = Hschoolchoice(*gptr);
                mitr=allmixgroups.begin();
                while((*mitr).Getgid()!=hSchool)
                {
                    mitr++;
                }
                newPerson->addgroup(hSchool);
                (*mitr).addperson(newPerson);


            }
            else if(regAge>16&& regAge<20 && college==1) /// person added to college
            {
                mitr=allmixgroups.begin();
                while((*mitr).Getgid()!=15)
                {
                    mitr++;
                }
                newPerson->addgroup(15);
                (*mitr).addperson(newPerson);

            }
            else if(hospitalC==4) /// random chance 1/26 of being in a hospital
            {
                /// hospital is mixing group 16
                mitr=allmixgroups.begin();
                while((*mitr).Getgid()!=16)
                {
                    mitr++;
                }
                newPerson->addgroup(16);
                (*mitr).addperson(newPerson);

            }
            personlist.push_back(newPerson);
            personID++;

        }

        allmixgroups.push_back(*newGroup);
        familyID++;
    }

    cout << "which mixing group would you like to infect? ";
    int infectedGroup;
    cin >> infectedGroup;

    mitr=allmixgroups.begin();
    while((*mitr).Getgid()!=infectedGroup)
    {
        mitr++;
    }
    (*mitr).infectgroup();
    (*mitr).Display();




    /// so now we have an interconnected population that has a group that has been infected
    int day = 1;
    char in = 'd';
    while(in!='X')
    {

        cout << "type d to continue a day ";
        cin >> in;
        system("cls");
        switch(in)
        {
        case 'd':
        {


            itr=personlist.begin();
            while(itr!=personlist.end())
            {
                if((*itr)->Getstatus()==1 || (*itr)->Getstatus()==2 || (*itr)->Getstatus()==3)
                {
                    (*itr)->Setstatusclock((*itr)->Getstatusclock()+1);
                }
                if((*itr)->Getstatus()==0)
                {
                    (*itr)->Setstatusclock(0);
                }
                if((*itr)->Getstatus()==2 && (*itr)->Getstatusclock()>6)
                {
                    int daysymp = InfectSympDist(*gptr);
                    if((*itr)->Getstatusclock()>daysymp)
                    {
                        (*itr)->Setstatus(3);
                    }
                }
                itr++;
            }

            mitr=allmixgroups.begin();
            while(mitr!=allmixgroups.end())
            {
                (*mitr).transmisionDay();
                mitr++;
            }


            int groupam, group1id, group2id;
            double mathg1, mathg2, chance;

            itr=personlist.begin();
            while(itr!=personlist.end())
            {
                if((*itr)->Getstatus()==1)
                {
                    group1id = (*itr)->getgroup1(); /// getting group 1 of person exposed

                    groupam = (*itr)->groupsize();
                    if(groupam==1)
                    {
                        mitr=allmixgroups.begin();
                        int i =1;
                        char breakloop = 'a';
                        while(mitr!=allmixgroups.end() ||  breakloop!='b')
                        {
                            if(i==group1id)
                            {
                                mathg1 = (*mitr).probabilityPerson();
                                breakloop='b';
                            }
                            mitr++;
                            i++;
                        }


                        double val = infectDis(*gptr);
                        if(val>=mathg1) ///means the person has become infected
                        {
                            (*itr)->Setstatus(2);
                        }
                    }
                    else if(groupam>=2)
                    {
                        group2id = (*itr)->getgroup2();
                        mitr=allmixgroups.begin();
                        int i =1;
                        int breakloop = 0;
                        while(mitr!=allmixgroups.end() ||  breakloop!=2)
                        {
                            if(i==group1id)
                            {
                                mathg1 = (*mitr).probabilityPerson();
                                breakloop++;
                            }
                            if(i==group2id)
                            {
                                mathg2 = (*mitr).probabilityPerson();
                                breakloop++;
                            }
                            mitr++;
                            i++;
                        }


                        chance = mathg1*mathg2;
                        double val = infectDis(*gptr);
                        if(val>=chance) ///means the person has become infected
                        {
                            (*itr)->Setstatus(2);
                        }
                    }
                }

                itr++;

            }



            mitr=allmixgroups.begin();
            while(mitr!=allmixgroups.end())
            {
                //       (mitr)->Display();
                mitr++;
            }


        }
        break;
        }
        cout << "Day: " << day << " of simulation.  " << endl;
        int infectCt = 0;
        int symCt = 0;
        int deadCt = 0;
        int expCt = 0;
        int sizeofpop = personlist.size();
        mitr=allmixgroups.begin();
        while(mitr!=allmixgroups.end())
        {
            expCt = expCt + (mitr)->expoCt();
            infectCt = infectCt + (mitr)->infectct();
            symCt = symCt + (mitr)->symtpct();
            deadCt = deadCt + (mitr)->deadct();

            mitr++;
        }

        cout << "Dead amount: " << deadCt << endl << "Symptomatic amount: " << symCt << endl << "Infected amount: " << infectCt << endl << "Exposed amount: " << expCt << endl;
        cout << "Negative amount: " << sizeofpop-expCt-deadCt-symCt-infectCt << endl;



        day++;



    }

    return 0;


}
