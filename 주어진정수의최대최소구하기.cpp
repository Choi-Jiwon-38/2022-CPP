#include <iostream>
using namespace std;

int main(void) {
    int t, n, inputNum, maxNum, minNum;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        maxNum = -10000;
        minNum = 10000;
        for (int j = 0; j < n; j++) {
            cin >> inputNum;
            if (inputNum < minNum) {
                minNum = inputNum;
            }
            if (inputNum > maxNum) {
                maxNum = inputNum;
            }
        }
        cout << maxNum << " " << minNum << endl;
    }
    return 0;
}