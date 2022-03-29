#include <iostream>
using namespace std;

void f1(int a, int b = 1); // int형 매개변수 a, b를 받아 실행되는 함수 (b의 기본값은 1)
int g1; // int형 전역 변수
int garray[3]; // int 리스트형 전역 변수

int main(void) {
    int i = 100, a[3];
    // 위는 main 함수의 지역 변수 i와 리스트 a
    {
        int i; // 11번 블록에서 사용되는 지역 변수(local variable)
        i = 1; // 12번째 줄의 지역 변수 i를 사용 
        a[0] = 20;
    }
    cout << "i = " << i << endl;  // main 함수의 지역 변수 i를 사용

    for (int i = 0; i < 3; i++) {} // 18번 블록에서 사용되는 지역 변수(local variable)

    cout << "i = " << i << endl;
    f1(i); // <- f1에 하나의 값만 들어갔으므로 i는 f1(a, b) 중에 a로 들어감 | b에는 기본값인 1이 들어감
    return 0;
}
void f1(int a, int b) {
    int c = 100;
    a = a + b + c;
}

