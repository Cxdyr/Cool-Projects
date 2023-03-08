#include "mixinggroup.h"
#include <iostream>

mixinggroup::mixinggroup(int n)
{
    //ctor

}

mixinggroup::~mixinggroup()
{
    //dtor
}


int mixinggroup::expoCt()
{
    int exCt = 0;
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==1)
        {
            exCt++;
        }
        itr++;
    }
    return exCt;;
}

int mixinggroup::infectct()
{
    int infectAm = 0;
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==2)
        {
            infectAm++;
        }
        itr++;
    }
    return infectAm;;
}

int mixinggroup::symtpct()
{
    int symAm = 0;
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==3)
        {
            symAm++;
        }
        itr++;
    }
    return symAm;;

}

int mixinggroup::deadct()
{
    int deadAm = 0;
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==4)
        {
            deadAm++;
        }
        itr++;
    }
    return deadAm;;
}




void mixinggroup::transmisionDay()
{



    int exposedAm = 0;
    int symtomaticAm = 0;
    int infectedAm = 0;
    int deadAm = 0;
    int totalMembers = 0;


    default_random_engine*gptr;
    gptr = new default_random_engine(time(NULL));



///collecting the amount of each type of person status to calculate the chances of various outcomes in each group
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==4)
        {
            deadAm++;
        }
        if((*itr)->Getstatus()==3)
        {
            symtomaticAm++;
        }
        if((*itr)->Getstatus()==2)
        {
            infectedAm++;
        }
        if((*itr)->Getstatus()==1)
        {
            exposedAm++;
        }
        totalMembers++;
        itr++;
    }


    ///the spread through the interconnected population

    if(infectedAm>0 || symtomaticAm>0 ||exposedAm>0) /// Anyone in a group that has a member who is infected is exposed, and anyone who is infected dies after day 7
    {
        itr=personlist.begin();
        while(itr!=personlist.end())
        {
            if((*itr)->Getstatus()!=4 && (*itr)->Getstatus()!=3 && (*itr)->Getstatus()!=2 && (*itr)->Getstatus()!=1)
            {
                (*itr)->Setstatus(1); /// setting negative members to exposed
            }
            if((*itr)->Getstatus()==1 && (*itr)->Getstatusclock()>1) ///if exposed but not infected after 2 days back to negative
            {
                (*itr)->Setstatus(0);
                (*itr)->Setstatusclock(0);
            }
            if((*itr)->Getstatus()==2 && (*itr)->Getstatusclock()>=9)
            {
                (*itr)->Setstatus(3);
            }
            if((*itr)->Getstatusclock()>12 && ((*itr)->Getstatus()==3 || (*itr)->Getstatus()==2))
            {
                (*itr)->Setstatus(4); /// setting symptomatic members past day 12 to dead
                (*itr)->Setstatusclock(NULL);
            }

            itr++;
        }
    }





}

double mixinggroup::probabilityPerson()
{



    int kidInfctAm = 0;
    int adultInfctAm =0;
    int totalInfctAm = 0;


    double infectionConstant = 0;
    double chance;

    double cA, cc, AA;

///first we count the amount of infected exposed symptomatic kids and adults
    itr=personlist.begin();
    while(itr!=personlist.end())
    {
        if(((*itr)->Getstatus()==3 || (*itr)->Getstatus()==2 || (*itr)->Getstatus()==1 && (*itr)->Getage()<18))
        {
            kidInfctAm++;
        }
        if(((*itr)->Getstatus()==1) || (*itr)->Getstatus()==2 || (*itr)->Getstatus()==3 && (*itr)->Getage()>=18)
        {
            adultInfctAm++;
        }
        itr++;
    }

    totalInfctAm = kidInfctAm + adultInfctAm;
///total amount of infected in group

    int infectSymptomDay2ctr = 0;
    int infectSymptomDay3ctr = 0;
    int infectSymptomDay4ctr = 0;

    int kidday3ctr = 0;
    int adultday3ctr = 0;
    int kidday2ctr = 0;
    int adultday2ctr =0;
    int kidday4ctr = 0;
    int adultday4ctr =0;

    itr=personlist.begin(); /// now we count the amount of people infected/symp on days 2,3,4-9,10-12
    ///and the amount of kids/adults that are in that mix for future fixing of calculations
    while(itr!=personlist.end())
    {
        if((*itr)->Getstatus()==2 ||  (*itr)->Getstatus()==3)
        {
            if((*itr)->Getstatusclock()==2)
            {
                infectSymptomDay2ctr++;
                if((*itr)->Getage()<18)
                {
                    kidday2ctr++;
                }
                else if((*itr)->Getage()>=18)
                {
                    adultday2ctr++;
                }

            }
            if((*itr)->Getstatusclock()==3 || (*itr)->Getstatusclock()>=11 && (*itr)->Getstatusclock()<13)
            {
                infectSymptomDay3ctr++;
                if((*itr)->Getage()<18)
                {
                    kidday3ctr++;
                }
                else if((*itr)->Getage()>=18)
                {
                    adultday3ctr++;
                }

            }
            if((*itr)->Getstatusclock()>=4 && (*itr)->Getstatusclock()<=10)
            {
                infectSymptomDay4ctr++;
                if((*itr)->Getage()<18)
                {
                    kidday4ctr++;
                }
                else if((*itr)->Getage()>=18)
                {
                    adultday4ctr++;
                }
            }

        }
        itr++;
    }
    /// first int is the total am of people to remove from the cA calculation
    ///second int is the total am of kids to remove from the cc calculation
    ///third int is the total am of adults to remove from the AA calculation
    int totalremovedcalculations = kidday2ctr+adultday2ctr+kidday3ctr+adultday3ctr+kidday4ctr+adultday4ctr;
    int totalremovedkidcalculations = kidday2ctr+kidday3ctr+kidday4ctr;
    int totalremovedadultcalculations = adultday2ctr+adultday3ctr+adultday4ctr;


    ///group ids 1-8 constant provided in paper, same with 8-16
    if(gid<=8)
    {
       chance = pow(0.99, totalInfctAm);
    }
    else if(gid>8&&gid<=16)
    {
        chance = pow(0.992, totalInfctAm);
    }
    else if(gid>16) ///over 16 is family and misc
    {
        /// if no extra infectous rates we do the basic calculation
        if(infectSymptomDay2ctr==0 && infectSymptomDay3ctr==0 && infectSymptomDay4ctr==0) ///if no one is infected past day 5 or 10
        {
            ///first we will do child to adult
            cA = pow(0.985, totalInfctAm);
            ///child to child
            cc = pow(0.97, kidInfctAm);
            ///adult to adult
            AA = pow(0.99, adultInfctAm);

            chance = cA*cc*AA; ///find the total prob and return
        }
        else ///if there are people on days with extra infectiousness rates
        {
            ///first we will do child to adult
            cA = pow(0.985, totalInfctAm-totalremovedcalculations); ///
            ///child to child
            cc = pow(0.97, kidInfctAm-totalremovedkidcalculations);
            ///adult to adult
            AA = pow(0.99, adultInfctAm-totalremovedadultcalculations);


            int extraProbA = pow(0.95,adultday2ctr); /// extra infectious adults day 2 prob (if none then this = 1 and affects nothing
            int extraProb2A = pow(0.9, adultday3ctr); /// adults day 3 and day 10,11
            int extraProb3A = pow(0.8, adultday4ctr); ///adults day 4-9
            int extraProbC = pow(0.85, kidday2ctr); ///kids day 2
            int extraProb2C = pow(0.7, kidday3ctr); ///kids day 3 and 10,11
            int extraProb3C = pow(0.4, kidday4ctr); ///kids day 4-9

            /// a lot of these will be 1 and affect nothing but should be close to what we need here
            chance = cA*cc*AA*extraProbA*extraProb2A*extraProb3A, extraProbC, extraProb2C, extraProb3C;
        }

    }

    ///return the decimal probability of the infection
    return chance;

}



