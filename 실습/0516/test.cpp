#include <iostream>
#include "Kvector.h"

int main() {
    Kvector<int> v1(3, 0); v1.print();
    cout << "v1 : " << v1 << endl;
    cout << "v1.sum() = " << v1.sum() << endl; // 왜 sum이 0이 아니라 1이 나오는거지...?

    Kvector<int *> v4(5, NULL); v4.print(); // null(0x0) 대신에 0 나와야ㅑ됨...
    int arr[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) { v4[i] = &arr[4 - i]; }
    cout << "v4 : " << v4 << endl; 
    for (int i = 0; i < 5; i++) { cout << *(v4[i]) << " "; }
    cout << endl;
}
// 엉엉 교수님 사렬2주세요