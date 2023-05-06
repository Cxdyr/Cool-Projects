#ifndef STORE_H
#define STORE_H
#include <list>
#include "Factory.h"
#include "Population.h"
using namespace std;

class Store
{
    public:
        Store();
        virtual ~Store();

        int Getprofit() { return profit; }
        void Setprofit(int val) { profit = val; }
        int GetcardsSold() { return cardsSold; }
        void SetcardsSold(int val) { cardsSold = val; }
        void CopyList(list<FinalCard>SendToStore){Shelves = SendToStore;}
        void ShowShelves();
        void SellTimeStep();

    private:
        int profit;
        int cardsSold;
        list<FinalCard>Shelves;
        list<FinalCard>SoldCards;
        list<FinalCard>::iterator fitr;
};

#endif // STORE_H
