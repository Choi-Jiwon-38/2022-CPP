#include <iostream>
using namespace std;

int main() {
    int t, flag;
    long long n, saveNum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        flag = 0;
        saveNum = 100;
        while (saveNum > 9) {
            if (flag != 0) {
                n = saveNum;
            } else {
                flag = 1;
            }
            // cout << "현재 n의 값은 " << n << endl;
            saveNum = 1;
            while (n > 0) {
                if (n % 10 != 0) {
                    saveNum *= (n % 10);
                }
                n /= 10;
            }
        }
        cout << saveNum << endl;
    }
}