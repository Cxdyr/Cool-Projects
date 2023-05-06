#include "Factory.h"

Factory::Factory()
{
    this->profit = 0;
    this->soldCards = 0;
}

Factory::~Factory()
{
    //dtor
}


void Factory::ChooseCards(Population Demand)
{
    int val = Demand.GettypeInflu();
    int dispincome = Demand.GetdispMoney();
    char popdemand;
    if(val==1){popdemand='A';}
    else if(val==2){popdemand='B';}
    else if(val==3){popdemand='C';}
    else if(val==4){popdemand='D';}


    citr = ToSellCards.begin();
    while(citr!=ToSellCards.end())
    {
            if(citr->Gettype()==popdemand && dispincome>0)
            {
            SendToStore.push_back(*citr);
            dispincome-=citr->Getvalue();
            this->soldCards++;
            this->profit+=3; ///each card sold by factory worth $3
            citr = ToSellCards.erase(citr);
            }
            citr++;
    }

}

void Factory::CopyList(list<Card>ALLSTACK, list<Card>::iterator citr) ///takes the master list of card designs from the lab and iterator
{
    citr=ALLSTACK.begin();
    while(citr!=ALLSTACK.end())
    {
        ///creating a card and setting its attributes to the attributes of the card design
        FinalCard fCard;
        fCard.Setid(citr->Getid());
        fCard.Setvalue(citr->Getvalue());
        fCard.Settype(citr->Gettype());
        fCard.Setrarity(citr->Getrarity());
        ///adding card to factory list
        ToSellCards.push_back(fCard);
        ///onto the next card design
        citr++;
    }
}


 void Factory::ShowFactoryCards()
{
    cout << "ALL FACTORY LISTS: " << endl << "CARDS WAITING TO BE SENT TO STORE..." << endl << "CARDS SENT TO STORE..." << endl;
    cout << "To Sell Cards: " << endl;
    citr=ToSellCards.begin();
    while(citr!=ToSellCards.end())
    {
        citr->ShowCard();
        citr++;
    }

    cout << "To Store Cards: " << endl;
    citr=SendToStore.begin();
    while(citr!=SendToStore.end())
    {
        citr->ShowCard();
        citr++;
    }

    cout << "TOTAL FACTORY PROFIT ($3 per card sold to store): $" << this->profit << endl;
    cout << "TOTAL FACTORY CARDS SOLD: " << this->soldCards << endl;
}

void Factory::EraseCards()
{
    citr=SendToStore.begin();
    while(citr!=SendToStore.end())
    {
        citr = SendToStore.erase(citr);
        citr++;
    }
}
