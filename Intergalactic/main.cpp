#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <fstream>
#include <ostream>
#include "ship.h"
#include "crew.h"
#include "planet.h"
#include "farm.h"
#include "fuelchamber.h"

using namespace std;


char menu()
{
    cout << "options: \n";
    cout << "a: enter farm \n";
    cout << "b: enter fuel incubation chamber \n";
    cout << "c: feed crew \n";
    cout << "d: view past planets \n";
    cout << "e: watch movies with crew \n";
    cout << "f: repair ship \n";
    cout << "x: \n";
    char val;
    cin >> val;
    return val;
}

void displayart(string file)
{
    string art;
    fstream f;
    f.open(file);
    while(!f.eof())
    {
        getline(f, art);
        cout << art << endl;
    }
    f.close();
}



int main()
{
    ///create ship
    ship ourShip;
    bool alive;

    ///create crew pointer / list of crew for main
    crew * newCrew;
    list<crew*>crewlist;
    list<crew*>::iterator citr;

    ///ask user for amount of crew members
    cout << "how many crew members will your ship provide shelter for? ";
    int val;
    cin >> val;
    system("cls");

    ///create crew members
    for(int i=1; i<=val; i++)
    {
        newCrew = new crew;
        newCrew->Setid(i);
        crewlist.push_back(newCrew);
        ourShip.addcrew(newCrew);
    }

    ///explain the plot of the simulation / game
    cout << endl << "hello captain, you are in charge of providing shelter and searching for a new \n";
    cout << "home for the human civilization. Your ship is on course to exit the milky way \n";
    cout << "galaxy and to enter a worm hole that will put us near habitable planets. You \n";
    cout << "must keep the crew healthy and happy while searching for our new home... \n";
    system("pause"); system("cls");

    ///create earth
    planet Earth;
    Earth.Setname("Earth"); Earth.Setgravity(9.81); Earth.SetsurvivableAt(1); Earth.SetsoilSigns(1); Earth.SetwaterSigns(1);

    ///create list of planets we have encountered, so far only earth. Add to list
    list<planet>planetlist;
    list<planet>::iterator pitr;
    planetlist.push_back(Earth);
    char planetc = 'e';

    ///create farm that is on ship & fuel creation chamber
    farm ourFarm; bool onfarm = false;
    fuelchamber ourFuelchamber; bool onfuel = false;

    ///random gen for distance traveled per time step, and hunger of crew
    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));
    uniform_int_distribution<int> distancegen1(15,30);
    uniform_int_distribution<int> distancegen2(60,120);
    uniform_int_distribution<int> fuellostgen(10,25);
    uniform_int_distribution<int> randomgen(3,5);
    uniform_int_distribution<int> moviegen(1,8);
    uniform_int_distribution<int> windsgen(1,10);
    uniform_int_distribution<int> planetgen(1,5);/// used later in program
    uniform_int_distribution<int> winddamge(20,55);
    ///start loop
    int distance;
    int day = 1;
    char input = '$';
    while(input!='x')
    {
        ///output to user
        displayart("shipart.txt");
        cout << "day " << day << endl;
        ourShip.Display();


        input = menu();
        switch(input)
        {
        case 'a':
            { ///farm chamber

                cout << "welcome to farm chamber \n";
                cout << "crew members: " << ourFarm.Getcrewct() << ", seed ct: " << ourFarm.Getseedct() << ", food ct: " << ourFarm.Getfoodct() << ", incubation time: " << ourFarm.Getincubationtime() << endl;
                cout << "options: \n";
                cout << "a: send crew to farm \n";
                cout << "b: return crew from farm \n";
                char val1;
                cin >> val1;
                switch(val1)
                {
                case 'a':
                    {
                        if(onfarm==false)
                        {
                        cout << "how many crew members would you like to send to farm: " << endl;
                        int crewfarm;
                        int ctr = 0;
                        cin >> crewfarm;
                        citr=crewlist.begin();
                        while(citr!=crewlist.end())
                        {
                            if(ctr<crewfarm && (*citr)->GetlocationID()==0)
                            {
                                (*citr)->SetlocationID(1);
                                ctr++;
                            }

                            citr++;
                        }
                        ourFarm.Setcrewct(ctr);
                        if(crewfarm!=ourFarm.Getcrewct()){cout << " you did not have enough available crew members to send the full amount to farm. \n";}
                        int seedtemp = ctr*50;
                        ourFarm.Setseedct(seedtemp);
                        int timeval = randomgen(*gptr);
                        ourFarm.Setincubationtime(timeval);
                        cout << ctr << " crew have been sent to farm, you have " << seedtemp << " seeds. ";
                        onfarm = true;
                        }
                        else
                        {
                        cout << "crew already on farm..." << endl;
                        }
                    }break;
                case 'b':
                    {
                        if(onfarm==true)
                        {
                        ourFarm.Display();
                        if(ourFarm.Getincubationtime()!=0)
                        {
                            cout << "seeds have not been incubated yet..." << endl;
                        }
                        else
                        {
                            onfarm = false;
                            ourFarm.Setseedct(0);
                            ourFarm.Setcrewct(0);
                            ourShip.Setfoodct(ourShip.Getfoodct()+ourFarm.Getfoodct());
                            ourFarm.Setfoodct(0);

                            citr=crewlist.begin();
                            while(citr!=crewlist.end())
                            {
                            if((*citr)->GetlocationID()==1)
                            {
                                (*citr)->SetlocationID(0);
                            }
                            citr++;
                            }

                        }
                        }
                        else
                        {
                        cout << "no crew on farm to return..." << endl;
                        }
                    }break;
                default:
                    {
                        cout << "not an option. " <<endl;
                    }break;
                }
            }break;
        case 'b':
            { ///fuel chamber
                cout << "welcome to fuel chamber \n";
                cout << "crew members: " << ourFuelchamber.Getcrewct() << ", prefuel ct: " << ourFuelchamber.Getprefuelct() << ", fuel ct: " << ourFuelchamber.Getfuelct() << ", incubation time: " << ourFuelchamber.Getincubationtime() << endl;
                cout << "options: \n";
                cout << "a: send crew to fuel chamber \n";
                cout << "b: return crew from fuel chamber \n";
                char val1;
                cin >> val1;
                switch(val1)
                {
                case 'a':
                    {
                        if(onfuel==false)
                        {
                        cout << "how many crew members would you like to send to farm: " << endl;
                        int crewfuel;
                        int ctr = 0;
                        cin >> crewfuel;
                        citr=crewlist.begin();
                        while(citr!=crewlist.end())
                        {
                            if(ctr<crewfuel && (*citr)->GetlocationID()==0)
                            {
                                (*citr)->SetlocationID(2);
                                ctr++;
                            }

                            citr++;
                        }
                        ourFuelchamber.Setcrewct(ctr);
                        if(crewfuel!=ourFuelchamber.Getcrewct()){cout << "you did not have enough available crew members to send the full amount to fuel chamber. \n";}
                        int fueltemp = ctr*60;
                        ourFuelchamber.Setprefuelct(fueltemp);
                        int timeval = randomgen(*gptr);
                        ourFuelchamber.Setincubationtime(timeval);
                        cout << ctr << " crew have been sent to fuel chamber, you have " << fueltemp << " liters of prefuel. ";
                        onfuel = true;
                        }
                        else
                        {
                        cout << " crew already in fuel chamber..." << endl;
                        }
                    }break;
                case 'b':
                    {
                        if(onfuel==true)
                        {
                        ourFuelchamber.Display();
                        if(ourFuelchamber.Getincubationtime()!=0)
                        {
                            cout << " fuel has not been incubated yet..." << endl;
                        }
                        else
                        {
                            onfuel = false;
                            ourFuelchamber.Setprefuelct(0);
                            ourFuelchamber.Setcrewct(0);
                            ourFuelchamber.Setincubationtime(0);
                            ourShip.Setfuelct(ourShip.Getfuelct()+ourFuelchamber.Getfuelct());
                            ourFuelchamber.Setfuelct(0);

                            citr=crewlist.begin();
                            while(citr!=crewlist.end())
                            {
                            if((*citr)->GetlocationID()==2)
                            {
                                (*citr)->SetlocationID(0);
                            }
                            citr++;
                            }

                        }
                        }
                        else
                        {
                        cout << " no crew in fuel chamber to return..." << endl;
                        }
                    }break;
                default:
                    {
                        cout << " not an option. " << endl;
                    }break;
                }
            }break;
        case 'c':
            { ///feed crew
                ourShip.FeedCrew();
            }break;
        case 'd':
            { /// showing planets encountered
                pitr = planetlist.begin();
                while(pitr!=planetlist.end())
                {
                    pitr->Display();
                    pitr++;
                }
            }break;
        case 'e': ///movie for crew
            {
                int movieval = moviegen(*gptr);
                switch(movieval)
                {
                case 1:
                    cout << "Dust storms ravaging earth... we are barely able to grow crops anymore. " ;
                    break;
                case 2:
                    cout << "Interstellar, by Christopher Nolan starts playing and the crew loves it. ";
                    break;
                case 3:
                    cout << "The Wolf of WallStreet, by Martin Scorsese starts playing and the crew likes it a lot. ";
                    break;
                case 4:
                    cout << "The Hateful 8, by Quentin Tarantino starts playing and the crew likes it a lot. ";
                    break;
                case 5:
                    cout << "Once Upon a Time in Hollywood, by Quentin Tarantino starts playing and the crew likes it a lot. ";
                    break;
                case 6:
                    cout << "The Office TV show starts playing and the crew likes it. ";
                    break;
                case 7:
                    cout << "Issues with the TV occur causing the show to be partially static but the crew enjoys each others company. ";
                    break;
                case 8:
                    cout << "Tenet, by Christopher Nolan starts playing and the crew likes it a lot. ";
                    break;
                }
                cout << endl;
                ourShip.WatchMovie();
            }break;
        case 'f':
            {
                if(ourShip.Gethealth()>350)
                {
                    cout << "ship cannot be further repaired..." << endl;
                }
                else
                {
                    int repair = winddamge(*gptr);
                    ourShip.Sethealth(ourShip.Gethealth()+repair);
                    cout << "our ship has been partially repaired..." << endl;
                }
            }break;

        default:
            {
                cout << "not an option. " <<endl;
            }break;

        }


        ///crew hunger/health/happiness conditions
        citr = crewlist.begin();
        while(citr!=crewlist.end())
        {
        if((*citr)->GetlocationID()!=3)
        {
            int hunger = randomgen(*gptr);
            int happiness = randomgen(*gptr);
            (*citr)->Sethunger((*citr)->Gethunger()-hunger);
            (*citr)->Sethappiness((*citr)->Gethappiness()-happiness);
            if((*citr)->Gethunger()<=0)
            {
                (*citr)->Sethunger(0);
                (*citr)->Sethealth((*citr)->Gethealth()-hunger);
            }
            if((*citr)->Gethealth()<=0)
            {
                (*citr)->SetlocationID(3); ///status is dead
            }
            if((*citr)->Gethappiness()<=0)
            {
                (*citr)->Sethappiness(0);
            }
        }
            citr++;
        }

        ///planet encounters
        if(ourShip.Getdistance()>100 && planetc=='e')
        {
            ///we have encountered mars
            planet Mars; Mars.Setgravity(3.721); Mars.SetsoilSigns(1); Mars.SetsurvivableAt(0); Mars.Setname("Mars"); Mars.SetwaterSigns(1); Mars.Setoversurv(0);
            planetlist.push_back(Mars);
            cout << "Passing Mars... " << endl;
            Mars.Display();
            planetc = 'm';
        }
        if(ourShip.Getdistance()>540 && planetc=='m')
        {
            ///we have encountered jupiter
            planet Jupiter; Jupiter.Setgravity(24.79); Jupiter.SetsoilSigns(0); Jupiter.SetsurvivableAt(0); Jupiter.Setname("Jupiter"); Jupiter.SetwaterSigns(1); Jupiter.Setoversurv(0);
            planetlist.push_back(Jupiter);
            cout << "Passing Jupiter..." << endl;
            Jupiter.Display();
            planetc = 'j';
        }
        if(ourShip.Getdistance()>998 && planetc=='j')
        {
            planet Saturn; Saturn.Setgravity(10.44); Saturn.SetsurvivableAt(0); Saturn.Setname("Saturn"); Saturn.SetwaterSigns(1); Saturn.SetsoilSigns(0); Saturn.Setoversurv(0);
            planetlist.push_back(Saturn);
            cout << "Passing Saturn..." << endl;
            Saturn.Display();
            planetc = 's';
        }
        if(ourShip.Getdistance()>1876 && planetc=='s')
        {
            planet  Uranus; Uranus.Setgravity(8.87); Uranus.SetsurvivableAt(0); Uranus.Setname("Uranus"); Uranus.SetwaterSigns(1); Uranus.SetsoilSigns(0); Uranus.Setoversurv(0);
            planetlist.push_back(Uranus);
            cout << "Passing Uranus..." << endl;
            Uranus.Display();
            planetc = 'u';
        }
        if(ourShip.Getdistance()>2400 && planetc=='u')
        {
            cout << "approaching wormhole... " << endl;
            cout << "GET READY..." << endl;
            system("pause"); system("cls");
            displayart("wormholeart.txt");
            system("pause"); system("cls");
            cout << "the wormhole warped space time and took us into a new galaxy..." <<endl;
            cout << "woah... we are in an entire new galaxy. " << endl;
            system("pause"); system("cls");
            planetc='n';
        }
        if(planetc=='n')
        {
            /// new galaxy randomly generates planet encounters not based on distance, based on randomness
            int planetrand = planetgen(*gptr);
            if(planetrand==1)
            {
                ///new planet encountered
                planet newPlanet;
                cout << "approaching new planet..." << endl;
                newPlanet.Display();
                cout << "what would you like to name this new planet? " << endl;
                string enter;
                cin.ignore();
                getline(cin, enter);
                newPlanet.Setname(enter);
                newPlanet.Display();
                planetlist.push_back(newPlanet);
                if(newPlanet.Getoversurv()==1)
                {
                    cout << "we have found a habitable planet... congratulations! " << endl;
                    cout << "simulation/game by Cody Rabie..." << endl;
                    input = 'x';
                }
            }
        }


        ///winds chance
        int winds = windsgen(*gptr);
        if(winds==1)
        {
            int dmg = winddamge(*gptr);
            cout << "Ship has encountered a gravitational disturbance causing " << dmg << " damage." <<endl;
            ourShip.Sethealth(ourShip.Gethealth()-dmg);
        }



        ///fuel/farm incubation checker, distance increaser, day increment, fuel decriment
        if(onfuel){ourFuelchamber.Incubate();} ///if crew members inside fuel chamber we will use time
        if(onfarm){ourFarm.Incubate();} /// if crew members inside farm we will use time
        if(ourShip.Getdistance()<350){ distance = distancegen1(*gptr);} ///gen distance on ship}
        else{ distance = distancegen2(*gptr);}
        ourShip.Setdistance(ourShip.Getdistance()+distance); ///ship distance step
        int fuellost = fuellostgen(*gptr); ///gen 10-25 fuel lost
        ourShip.Setfuelct(ourShip.Getfuelct()-fuellost); ///fuel lost each run
        day++; /// day step


        ///checking for at least 1 living troop, fuel in ship, and health on ship
        alive = ourShip.CheckCrew();
        if(alive!=true){cout << "we have failed our mission... "; system("pause"); input ='x';}
        system("pause"); system("cls");
    }


    return 0;
}
