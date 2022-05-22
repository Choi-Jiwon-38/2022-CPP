#include <iostream>
#include <exception>
#include "Bvector.h"
#ifndef __BITSET__
#define __BITSET__

class IncompatibleException : public std::exception {
public:
    int first, second;
    IncompatibleException(int f, int s): first(f), second(s) {
    }
};

class BitSet : public Bvector
{
    public:
        BitSet(int sz = 32);
    void insert(int v);
    friend BitSet operator+(const BitSet& v1, const BitSet& v2);
    friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};
#endif
