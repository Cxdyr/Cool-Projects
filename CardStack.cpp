#include "CardStack.h"

CardStack::CardStack()
{
    //ctor
}

CardStack::~CardStack()
{
    //dtor
}

void CardStack::GenStack(int stackID, default_random_engine*ptr)
{

    uniform_int_distribution<int>AmGen(4,8); ///amount of card design to be generated
    uniform_int_distribution<int>TypeGen(1,4); ///1-4 rng type of card attribute
    uniform_int_distribution<int>RarityGen(1,7); ///1-8 rng rarity attribute
    uniform_int_distribution<int>JackPot(1,15); ///1/15 chance of jackpot card, extra value
    int tAm = AmGen(*ptr);
    int tType, tRarity, CardValue;

    for(int i=0; i<tAm; i++)
    {
        int jacktemp = JackPot(*ptr);
        ///generating Card Attributes
        CardValue = 0;
        ///creating new card design object and setting attributes accordingly
        Card tCard;
        tCard.Setid(stackID);
        tType = TypeGen(*ptr);
        if(tType==1){tCard.Settype('A'); CardValue+=1;}
        else if(tType==2){tCard.Settype('B');CardValue+=2;}
        else if(tType==3){tCard.Settype('C');CardValue+=3;}
        else if(tType==4){tCard.Settype('D');CardValue+=4;}
        else{tCard.Settype('Z');}
        tRarity = RarityGen(*ptr);
        if(tRarity==1){tCard.Setrarity("Rare");CardValue+=100;}
        else if(tRarity==2 || tRarity ==3){tCard.Setrarity("Uncommon");CardValue+=10;}
        else {tCard.Setrarity("Common");CardValue+=1;}
        if(jacktemp==15 && tCard.Getrarity()=="Rare"){CardValue+=100;}
        tCard.Setvalue(CardValue);
        ///sorting into lists based on rarity
        string tempRare = tCard.Getrarity();
        if(tempRare=="Rare"){RareCardStack.push_back(tCard);}
        else if(tempRare=="Uncommon"){UncommonCardStack.push_back(tCard);}
        else {CommonCardStack.push_back(tCard);}
        ///putting card design into master list
        ALLSTACK.push_back(tCard);
    }
}

void CardStack::DisplayRare()
{
    cout << endl << "Rare Card Designs:  " << endl;
    ritr = RareCardStack.begin();
    while(ritr!=RareCardStack.end())
    {
        ritr->ShowCard();
        ritr++;
    }
}

void CardStack::DisplayUncommon()
{
    cout << endl << "Uncommon Card Designs:  " << endl;
    ritr = UncommonCardStack.begin();
    while(ritr!=UncommonCardStack.end())
    {
        ritr->ShowCard();
        ritr++;
    }
}

void CardStack::DisplayCommon()
{
    cout << endl << "Common Card Designs:  " << endl;
    ritr = CommonCardStack.begin();
    while(ritr!=CommonCardStack.end())
    {
        ritr->ShowCard();
        ritr++;
    }
}
