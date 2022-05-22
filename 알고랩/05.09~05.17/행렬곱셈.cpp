#include <iostream>
using namespace std;

int main() {
    int testcase;
    int r, s, t;

    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        cin >> r >> s >> t;

        int A[r][s]; 
        int B[s][t];
        int C[r][t]; // 행렬 A와 행렬 B를 곱셈한 결과

        for (int i = 0; i < r; i++) { // 행렬 A 초기화
            for (int j = 0; j < s; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < s; i++) { // 행렬 B 초기화
            for (int j = 0; j < t; j++) {
                cin >> B[i][j];
            }
        }

        int sumNum;
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < t; j++) {
                sumNum = 0;
                for (int i = 0; i < s; i++) { 
                    sumNum += A[k][i] * B[i][j];
                }
                C[k][j] = sumNum;
            }
        }


        // // 디버깅 코드
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < s; j++) {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // for (int i = 0; i < s; i++) {
        //     for (int j = 0; j < t; j++) {
        //         cout << B[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < t; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
}