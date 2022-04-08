#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        int beforeNum, currNum;
        cin >> beforeNum;
        int flag = 0;
        int answer = 0;
        for (int j = 0; j < n-1; j++) {
            cin >> currNum;
            if (flag == 1) {
                if (currNum < beforeNum) {
                    answer ++;
                    flag = 0;
                }
            } else {
                if (currNum > beforeNum) {
                    flag = 1;
                }
            }
            beforeNum = currNum;
        }
        cout << answer << endl;
    }
}

