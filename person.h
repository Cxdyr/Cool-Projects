#ifndef PERSON_H
#define PERSON_H
#include <list>
using namespace std;
class person
{
    public:
        person(int n);
        virtual ~person();

        void addgroup(int gid){groupids.push_back(gid);}
        int groupsize();
        int getgroup1();
        int getgroup2();
        void Setid(int val){id=val;}
        int Getid(){return id;}
        int Getstatus() { return status;}
        void Setstatus(int val){status = val;}
        int Getstatusclock() { return statusclock; }
        void Setstatusclock(int val) { statusclock = val; }
        int Getage() { return age; }
        void Setage(int val) { age = val; }

        void Display();




    private:
        int id;
        int status;
        int statusclock;
        int age;
        list<int>groupids;
        list<int>::iterator gpitr;


};

#endif // PERSON_H
