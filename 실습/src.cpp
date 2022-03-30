#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void init_array(int a[], int n) { // 크기가 n인 배열에 1~999까지의 수 n개를 넣어 초기화
    for (int i = 0; i < n; i++) {
        srand(n + i);
        int num = rand() % 999 + 1;
        a[i] =  num;
    } 
}

int sum_array1(int a[], int n) { // 배열에 있는 요소를 모두 더한 뒤 return
    int sumNum = 0;
    for (int i = 0; i < n; i++) {
        sumNum += a[i];
    }
    return sumNum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { cout << "one command line argument needed\n"; return -1; };

    int n = atoi(argv[1]); // n은 시드 번호 + 배열의 길이
    n = (n < 1) ? 1 : n; // n이 1보다 작은 경우에는 1로 초기화
    n = (n > 10) ? 10 : n; // n이 10보다 큰 경우에는 10으로 초기화

    int array[n];

    int *a = array;
    if (!a) { cout << "allocation failed.\n"; return -1;};
    int s;

    init_array(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    s = sum_array1(a, n);

    cout << endl << s << endl;
}