template<class T>
Kvector<T>::Kvector(int sz, T value) : len(sz)
{
    cout << this << " : Kvector(" << sz << "," << value << ")\n";
    if (!sz) { m = NULL; return; }
    m = new T[sz];
    for (int i = 0; i < len; i++) { m[i] = value; }
}
template<class T>
Kvector<T>::Kvector(const Kvector& v)
{
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    if (!len) { m = NULL; return; }
    m = new T[len];
    for (int i=0; i<len; i++) m[i] = v.m[i];
}
template<class T>
Kvector<T>::~Kvector()
{
    cout << this << " : ~Kvector() \n";
    delete[] m;
}
template<class T>
Kvector<T>& Kvector<T>::operator=(const Kvector& v){
    cout << "Kvector::operator= " << &v << endl;
    delete[] m;
    len = v.len;
    for (int i=0; i<len; i++) m[i] = v.m[i];
    return *this;
}
template<class T>
bool Kvector<T>::operator==(const Kvector& v)
{
    return (len == v.len) && (*m == *(v.m));
}
template<class T>
bool Kvector<T>::operator!=(const Kvector& v)
{
    return !(*this == v);
}