using namespace std;
template <class T>
Kvector<T>::Kvector(int sz, T value): len(sz) {
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
template <class T>
Kvector<T>::Kvector(const Kvector& v) {
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
template <class T>
Kvector<T>::~Kvector() {
    cout << this << " : ~Kvector() \n";
    delete[] m;
}
template <class T>
Kvector<T>& Kvector<T>::operator=(const Kvector& v){
    *m = *k.m; len = k.len;
    for (int i = 0; i < len; i++) {
        m[i] = k.m[i];
    }
    return *this;
}
template <class T>
bool Kvector<T>::operator==(const Kvector& a){
    return (( a.len == b.len ) && ( *a.m == *b.m ));
}
template <class T>
bool Kvector<T>::operator!=(const Kvector& a) {
    return !( a == b );
}

// 실습 메인코드
int main() {
    Kvector<int> v1(3, 0); v1.print();
    cout << "v1 : " << v1 << endl;
    cout << "v1.sum() = " << v1.sum() << endl;

    Kvector<int *> v4(5, NULL); v4.print();
    int arr[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) v4[i] = &arr[4-i];
    cout << "v4 : " << v4 << endl;
    for (int i = 0; i < 5; i++) cout << *(v4[i]) << " ";
    cout << endl;
}