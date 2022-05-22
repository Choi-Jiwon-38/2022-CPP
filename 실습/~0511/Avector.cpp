#include <iostream>
using namespace std;

class Kvector {
protected:
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(Kvector& v);
    ~Kvector() {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    }
    void print() {
        for (int i = 0; i < len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = nullptr;
        len = 0;
    }
    int size() { return len; }
    Kvector& operator=(const Kvector& k);
    int& operator[](const int idx){return m[idx];}
friend ostream& operator<<(ostream& os, const Kvector& k) {
    
    for (int i = 0; i < k.len; i++) {
        os << k.m[i] << " ";
    }
    return os;
}
friend bool operator==(const Kvector& a, const Kvector& b);
};


Kvector::Kvector(int sz, int value) {
    len = sz;
    cout << this << " : Kvector(int, int)" << endl;
    if (len == 0) {
        m = nullptr;
    } else {
        m = new int[len];
        for (int i = 0; i < len; i++) {
            m[i] = value;
        }
    }
} 

Kvector::Kvector(Kvector& v) {
    len = v.len;
    cout << this << " : Kvector(Kvector&)" << endl;
    if (len == 0) {
        m = nullptr;
    } else {
        m = new int[len];
        for (int i = 0; i < len; i++) {
            m[i] = v.m[i];
        }
    }
    
}

// 연산자 중복 friend 선언

Kvector& Kvector::operator=(const Kvector& k) { // '=' 연산자 중복 - 깊은 구현이 필요하여 구현 - 28page
    *m = *k.m; len = k.len;
    for (int i = 0; i < len; i++) {
        m[i] = k.m[i];
    }
    return *this;
}

bool operator==(const Kvector& a, const Kvector& b) { // '==' 연산자 중복 - bool 타입으로 반환하도록 구현
    return (( a.len == b.len ) && ( *a.m == *b.m ));
}

bool operator!=(const Kvector& a, const Kvector& b) { // '!=' 연산자 중복 - '==' 연산자를 호출하는 것으로 구현 <- friend 선언 필요 없음
    return !( a == b );
}

#define N 3
class Avector : public Kvector {
    char table[N];
public:
    Avector(int sz = 0, int v = 0, const char *t = "abc"): Kvector(sz, v) {
        
        table[0] = *t;
        cout << this << " : Avector(int, int, const char*)" << endl;
    }
    void setTable(const char *t) {};
friend ostream& operator<<(ostream& os, const Avector& v);
};

ostream& operator<<(ostream& os, const Avector& v) {
    for (int i = 0; i < v.len; i++) {
        os << "디버깅 필요" << " ";
    }
    return os;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "usage : ./Avector pqr\n";
        return 1;
    }
    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << (v1 == v2) << endl;
    cout << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << v1 << endl;
    v1.print();
    cout << v2 << endl;
    v2.print();
    cout << v3 << endl;
    v3.print();
    cout << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
}