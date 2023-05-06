#ifndef FACTORY_H
#define FACTORY_H
#include "CardStack.h"
#include "FinalCard.h"
#include "Population.h"
class Factory
{
    public:
        Factory();
        virtual ~Factory();

        int Getprofit() { return profit; }
        void Setprofit(int val) { profit = val; }
        int GetsoldCards() { return soldCards; }
        void SetsoldCards(int val) { soldCards = val; }
        void CopyList(list<Card>ALLSTACK, list<Card>::iterator citr); ///takes the master list of card designs from the lab and iterator
        void EraseCards();
        void ChooseCards(Population Demand); ///chooses cards to send to store based on population demand
        void ShowFactoryCards();
        list<FinalCard> GetList(){ return SendToStore;}

    private:
        int profit; ///factory profit
        int soldCards;
        list<FinalCard> ToSellCards; ///list of cards to be sold
        list<FinalCard> SendToStore;
        list<FinalCard>::iterator citr; ///iterator
};

#endif // FACTORY_H
