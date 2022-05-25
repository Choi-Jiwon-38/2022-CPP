#include <iostream>
#ifndef __TEAM__
#define __TEAM__
#include "Kvector.h"

class Team{
public:
    string name;
    int victory;
    Team(const string& n="X", int v=0) : name(n), victory(v){}
    Team& operator+=(const Team& rhs){
        victory += rhs.victory;
        return *this;
    }
friend Team operator+(Team a, const Team& b);
friend bool operator==(const Team& a, const Team& b);
friend bool operator!=(const Team& a, const Team& b);
friend ostream& operator<<(ostream& os, const Team& n);
};
#endif