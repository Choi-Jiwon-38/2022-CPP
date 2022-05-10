/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main() { 
    int t, size;
    int count;
    string inputNum;


    cin >> t;

    for (int i = 0; i < t; i++) {
        count = 0; // count 0으로 초기화
        cin >> inputNum;
        size = inputNum.size();
        int mock[100] = {};

        while (inputNum.size() > 1) {
            int tailNum = inputNum[size - 1] - 48;
            
            inputNum = inputNum.substr(0, size - 1);
            size = inputNum.size();
            
            mock[count++] = tailNum;

            int bodyNum[size];

            
            for (int i = 0; i < size; i++) {
                bodyNum[i] = inputNum[i] - 48; // char형을 int형으로 반환 후 저장
            }

            int tempNum[size] = {0, };
            tempNum[size - 1] = tailNum;
            int resultNum[size];

            for (int i = size - 1; i > -1; i--) {
                int num1 = bodyNum[i];
                int num2 = tempNum[i];

                int subNum = num1 - num2;
                if (subNum < 0) {  
                    resultNum[i] = subNum + 10;
                    bodyNum[i - 1] = bodyNum[i - 1] - 1;
                } else {
                    resultNum[i] = subNum;
                }
            }
            
            inputNum = "";
            
            int countingZero = 0;
            
            for (int i = 0; i < size; i++) {
                if (resultNum[i] == 0) {
                    countingZero++;
                } else {
                    break;
                }
            }
            
            for (int i = countingZero; i < size; i++) {
                inputNum += resultNum[i] + 48;
            }
        }
        if (inputNum == "") {
            for (int i = count - 1; i > -1; i--) {
                cout << mock[i];
            }
        } else {
            cout << 0;
        }
        cout << endl;
    }
}
