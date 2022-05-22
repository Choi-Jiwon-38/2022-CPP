#include "MyComplex.h"
#include <cmath>
#include <cstdlib>

// 생성자 (Constructor)
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// 복사 생성자 (Copy constructor)
myComplex::myComplex(const myComplex& number) {
    realPart = number.realPart;

    imaginaryPart = number.imaginaryPart;
}

// 접근자 (Accessor functions) 
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}

// 변경자 (Mutator functions)
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// 이항연산자 오버로딩 (Overloaded binary operator)
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return (*this) + myComplex(value);
}
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return (*this) - myComplex(value);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + number.realPart * imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}

// Overloaded assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart; // 포인터를 통해 멤버를 접근 | a -> b 와 (*a).b는 같음
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myComplex& myComplex::operator +=(const myComplex& number) 
{
    this->realPart += number.realPart;
    this->imaginaryPart += number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    realPart += value;
    return *this; 
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    this->realPart -= number.realPart;
    this->imaginaryPart -= number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    realPart -= value;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number) // 다시 1
{
    const myComplex tmp(*this);
    this->realPart = tmp.realPart * number.realPart - tmp.imaginaryPart * number.imaginaryPart;
    this->imaginaryPart = tmp.realPart * number.imaginaryPart + tmp.imaginaryPart * number.realPart;
    return *this;
}
myComplex& myComplex::operator *=(int value) // 다시 2
{
    realPart *= value;
    imaginaryPart *= value;
    return *this;
}

// 관계연산자 오버로딩 (Overladed relational operators)
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}

bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// 단항연산자 오버로딩 (Overloaded unary operators)
myComplex myComplex::operator -()
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~() 
{
    return myComplex(realPart, -imaginaryPart);
}
myComplex& myComplex::operator ++() // 전위 증가
{
    realPart++;
    return *this;
}
myComplex& myComplex::operator --() // 전위 감소
{
    realPart--;
    return *this;
}
myComplex myComplex::operator ++(int) // 후위 증가
{
    myComplex tmp = myComplex(*this);
    realPart++;
    return tmp;
}
myComplex myComplex::operator --(int) // 후위 감소
{
    myComplex tmp = myComplex(*this);
    realPart--;
    return tmp;
}

// private 함수들
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}

ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}

istream &operator >>(istream &isStream, myComplex& number)
{
    isStream >> number.realPart >> number.imaginaryPart;
    return isStream;
}
myComplex operator +(int value, const myComplex& number)
{
    return myComplex(value) + number;
}
myComplex operator -(int value, const myComplex& number)
{
    return myComplex(value) - number;
}
myComplex operator *(int value, const myComplex& number)
{
    return myComplex(value) * number;
}