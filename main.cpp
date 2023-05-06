#include <iostream>
#include "Factory.h"
#include "Store.h"
using namespace std;

int main()
{

    cout << "Welcome to Cody's Card Factory " << endl;
    cout << "How many days would you like to witness the simulation? ";
    int days;
    cin >> days; /// time steps program runs


    ///below are our declarations
    CardStack Lab;
    Factory Fact;
    Population Demand;
    Store Seller;

    int StackID = 1;
    default_random_engine *gptr;
    gptr = new default_random_engine(time(NULL));


    for(int i=0; i<days; i++)
    {
        Lab.GenStack(StackID, gptr); ///lab creates designs randomly
        Fact.CopyList(Lab.GetList(),Lab.Getit()); ///factory takes the list of designs and creates real cards with the design information
        Demand.RandomizeDemand(gptr);///population decides what randomness they are liking that time step (basic read class if confused)
        Fact.ChooseCards(Demand);
        Seller.CopyList(Fact.GetList());
        Fact.EraseCards();
        Seller.SellTimeStep();
        StackID++;///each time step a new stack of cards is generated, thus the stack id ++
    }
    cout << "ALL CARD DESIGNS FROM LAB: " << endl;
    Lab.DisplayRare();
    Lab.DisplayUncommon();
    Lab.DisplayCommon();
    cout << endl;
    Fact.ShowFactoryCards();
    Seller.ShowShelves();

}
