#include <iostream>
#include "BitSet.h"
using namespace std;

BitSet::BitSet(int sz) : Bvector(sz) { }
void BitSet::insert(int v) { set(v); }

BitSet operator+(const BitSet& v1, const BitSet& v2) {
    if (v1.NBITS != v2.NBITS) {
        throw IncompatibleException(v1.NBITS, v2.NBITS);
    } else {
        BitSet tmp(v1.NBITS);
        for (int i = 0; i < tmp.size(); i++) {
            if (v1[i] == 1 || v2[i] == 1) {
                tmp.set(i); // idx를 저장해야 하므로 1이 아닌 i를 set한다.
            }
        } 
        return tmp;
    }
}

::ostream& operator<<(::ostream& os, const BitSet& s) {
    os << "{ ";
    for (int i = 0; i < s.NBITS; i++) {
        if (s.bit(i) == 1) {
            os << i << " ";
        }
    }
    os << " }";
    return os;
}


int main(int agrc, char *argv[]) {
    BitSet b1(132), b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    try{
        cout << "b1+b2= " << b1+b2 << endl;
    } catch(IncompatibleException& e) {
        cout << "In + operation, the operands are not compatible." << endl;
        cout << "The size of the fisrt BitSet is" << e.first << endl;
        cout << "The size of the fisrt BitSet is" << e.second << endl;
    }
}