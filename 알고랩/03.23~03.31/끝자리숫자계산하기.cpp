#include <iostream>
using namespace std;

int main() {
    unsigned int t, n, inputNum, answer;
    cin >> t;
    for (int i = 0; i < t; i++) {
        answer = 1;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> inputNum;
            answer *= (inputNum % 10);
            answer = answer % 10;
        }
        cout << answer << endl;
    }
}