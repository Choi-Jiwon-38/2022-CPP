#include <iostream>
#include "Kvector.h"
#ifndef __BVECTOR__
#define __BVECTOR__

class Bvector : public Kvector {
    protected:
        unsigned int *u_m;
        const int NBITS;
    public:
        Bvector(int nbits = 32);
        Bvector(const Bvector& e);
        bool bit(int pos) const; // pos번째의 bit의 값을 false 혹은 true로 리턴
        void set(int pos); // pos번째의 bit 값을 1로 초기화
        void reset(int pos); // pos번쨰의 bit 값을 0으로 초기화
        int size() const { return NBITS; } // len이 아니라 NBITS를 리턴
        void claer() { for (int i = 0; i < len; i++) m[i] = 0; } // 모든 bit를 false(0)로 clear함
        void print() const ;
    bool operator[] (int idx) const { return bit(idx); } // reference가 아닌 객체를 반환해줌
    Bvector& operator=(const Bvector& v);
    friend std::ostream& operator << (std::ostream& os, const Bvector& v);
};
#endif