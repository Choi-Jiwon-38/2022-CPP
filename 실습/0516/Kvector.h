#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__
using namespace std;

template <class T>
class Kvector
{
    T *m;
    int len;
public:
    Kvector(int sz = 0, T value = 0);
    Kvector(const Kvector& v);
    ~Kvector();
    void print() const
    {
        cout << "Kvector: ";
        for (int i = 0; i < len; i++) cout << (this->m[i]) << " ";
        cout << endl;
    }

    void clear() {
        delete[] m;
        m = NULL;
        len = 0;
    }
    int size() const { return len; }
Kvector& operator=(const Kvector& v);
bool operator==(const Kvector& v);
bool operator!=(const Kvector& v);
T& operator[](int idx) { return m[idx]; }
const T& operator[](int idx) const { return m[idx]; }
T sum() const
{
    T s;
    if (len <= 0) {
        return s;
    }
    s = m[0];
    for (int i = 1; i < len; i++) s += m[i];
    return s; // 왜 +1된 값이 나올까
}
friend ostream& operator<<(ostream& os, const Kvector<T>& v)
{   
    for (int i = 0; i < v.len; i++) os << v.m[i] << " ";
    return os;
}
};
#include "Kvector.cpp"
#endif