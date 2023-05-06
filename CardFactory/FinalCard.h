#ifndef FINALCARD_H
#define FINALCARD_H
#include <string>
#include <iostream>

using namespace std;

class FinalCard
{
public:
    FinalCard();
    virtual ~FinalCard();

   int Getid(){return id;}
    void Setid(int val){id = val;}
    char Gettype(){return type;}
    void Settype(char val){type = val;}
    string Getrarity(){return rarity;}
    void Setrarity(string val){rarity = val;}
    int Getvalue(){return value;}
    void Setvalue(int val){value = val;}
    string Getsold(){return sold;}
    void Setsold(string val){sold = val;}
    void ShowCard();


private:
    int id;
    int value;
    char type;
    string rarity;
    string sold;

};

#endif // FINALCARD_H
