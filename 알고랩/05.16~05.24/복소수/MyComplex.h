#pragma once
#ifndef _MYCOMPLEX_H_
#define _MYCOMPlEX_H_
#include <iostream>
using namespace std;
class myComplex {
public:
    // 생성자 (Constructor)
    myComplex(int real = 0, int imag = 0);
    // 복사 생성자 (Copy constructor)
    myComplex(const myComplex& number);

    // 접근자 (Accessor functions) 
    int getRealPart() const;
    int getImaginaryPart() const;

    // 변경자 (Mutator functions)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);

    // 이항연산자 오버로딩 (Overloaded binary operator)
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;


    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);
    myComplex& operator +=(const myComplex& number);
    myComplex& operator +=(int value);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);

    // 관계연산자 오버로딩 (Overladed relational operators)
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;

    // 단항연산자 오버로딩 (Overloaded unary operators)
    myComplex operator -();
    myComplex operator ~();
    myComplex& operator ++();
    myComplex& operator --();
    myComplex operator ++(int);
    myComplex operator --(int);

private:
    int realPart;
    int imaginaryPart;
    int norm() const;

    friend ostream& operator <<(ostream& outStream, const myComplex& number);
    friend istream& operator >>(istream& inStream, myComplex& number);
    friend myComplex operator +(int value, const myComplex& number);
    friend myComplex operator -(int value, const myComplex& number);
    friend myComplex operator *(int value, const myComplex& number);
};
#endif