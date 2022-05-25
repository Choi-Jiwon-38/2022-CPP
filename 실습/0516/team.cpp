#include <iostream>
#include "team.h"

Team operator+(Team a, const Team& b){
    a += b;
    return a;
}
bool operator==(const Team& a, const Team& b){
    return (a.name == b.name);
}
bool operator!=(const Team& a, const Team& b){
    return !(a==b);
}
ostream& operator<<(ostream& os, const Team& n){
    os << n.name << "(" << n.victory << ")";
    return os;
}
