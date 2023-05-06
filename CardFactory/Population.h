#ifndef POPULATION_H
#define POPULATION_H
#include <random>
#include <ctime>
using namespace std;
class Population
{
    public:
        Population();
        virtual ~Population();

        int GetdispMoney() { return dispMoney; }
        void SetdispMoney(int val) { dispMoney = val; }
        int GettypeInflu() { return typeInflu; }
        void SettypeInflu(int val) { typeInflu = val; }
        void RandomizeDemand(default_random_engine*ptr);


    private:
        int dispMoney;
        int typeInflu;
};

#endif // POPULATION_H
