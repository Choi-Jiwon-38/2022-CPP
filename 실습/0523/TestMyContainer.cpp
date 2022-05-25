#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;

template <class T1, class T2>
ostream& operator <<(ostream& os, const pair<T1, T2>& p)
{
    os << "[" << p.first << "]" << p.second;                                                                                                                                                                                                                                                                                                            
    return os;
}
template <class T>
void print_container(const T& container, string s = "")
{
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for (; it != container.end(); it++)
    {
        cout << *it << " ";
    } 
    cout << endl;
}


int main() {
    // 단일 원소인 경우
    int a[10] = {3, 7, 3, 1, 2, 7, 0, 5, 4, 6};
    vector<int> v;
    deque<int> dq;
    list<int> li;
    set<int> s;
    multiset<int> ss;
    // 원소가 pair로 오는 경우
    map<int, int> m;
    multimap<int, int> mm;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(a[i]);
        dq.push_back(a[i]);
        li.push_back(a[i]);
        s.insert(a[i]);
        ss.insert(a[i]);

        m[i] = a[i];
        mm.insert(pair<int, int>(i, a[i]));
    }

    print_container(v, "v = ");
    print_container(dq, "dq = ");
    print_container(li, "li = ");
    print_container(s, "s = ");
    print_container(ss, "ss = ");

    print_container(m, "m = ");
    print_container(mm, "mm = ");
}