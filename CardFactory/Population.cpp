#include "Population.h"

Population::Population()
{
    //ctor
}

Population::~Population()
{
    //dtor
}

void Population::RandomizeDemand(default_random_engine*ptr)
{

    uniform_int_distribution<int>IncomeGen(20,200);
    uniform_int_distribution<int>FavorGen(1,4);

    int tI = IncomeGen(*ptr);
    int tF = FavorGen(*ptr);

    this->dispMoney = tI;
    this->typeInflu = tF;

}
