#include "Store.h"

Store::Store()
{
    this->profit = 0;
}

Store::~Store()
{
    //dtor
}

void Store::ShowShelves()
{
    cout << "Store Data:  " << endl;
    cout << "Current Shelves: " << endl;
    fitr = Shelves.begin();
    while(fitr!=Shelves.end())
    {
        fitr->ShowCard();
        fitr++;
    }
    cout << endl << "SOLD CARDS: " << endl;
    fitr = SoldCards.begin();
    while(fitr!=SoldCards.end())
    {
        fitr->ShowCard();
        fitr++;
    }
    cout << "TOTAL STORE PROFIT: $" << this->profit << endl;
}

void Store::SellTimeStep()
{

    fitr=Shelves.begin();
    while(fitr!=Shelves.end())
    {


        if(fitr->Getsold()!="SOLD")
        {
        fitr->Setsold("SOLD");
        this->profit+= fitr->Getvalue()-3;
        SoldCards.push_back(*fitr);
        fitr = Shelves.erase(fitr);
        }
        fitr++;
    }
}
