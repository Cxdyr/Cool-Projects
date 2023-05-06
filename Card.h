#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
    Card();
    virtual ~Card();

    int Getid(){return id;}
    void Setid(int val){id = val;}
    char Gettype(){return type;}
    void Settype(char val){type = val;}
    string Getrarity(){return rarity;}
    void Setrarity(string val){rarity = val;}
    int Getvalue(){return value;}
    void Setvalue(int val){value = val;}

    void ShowCard();


private:
    int id;
    int value;
    char type;
    string rarity;
    /// notice there is no sold variable, these are designs, not cards themselves

};

#endif // CARD_H
