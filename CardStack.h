#ifndef CARDSTACK_H
#define CARDSTACK_H
#include "Card.h"
#include <list>
#include <random>
#include <ctime>
using namespace std;

class CardStack
{
    public:
        CardStack();
        virtual ~CardStack();
        void GenStack(int StackID, default_random_engine*ptr); ///takes the stack id from main which ++ and random ptr
        void DisplayRare();
        void DisplayUncommon();
        void DisplayCommon();
        list<Card> GetList(){return this->ALLSTACK;} ///returning the master list of all card designs, will be called in factory
        list<Card>::iterator Getit(){return this->ritr;} ///returning the list iterator, will be called in factory

    private:
        list<Card> ALLSTACK; ///master design list
        list<Card> RareCardStack; ///rare design list
        list<Card> UncommonCardStack; ///uncommon design list
        list<Card> CommonCardStack; ///common design list
        list<Card>::iterator ritr;; ///iterator
};

#endif // CARDSTACK_H
