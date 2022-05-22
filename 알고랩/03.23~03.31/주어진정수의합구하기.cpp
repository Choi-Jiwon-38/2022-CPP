#include <iostream>
using namespace std;

int main() {
    int t, n, inputNum ,answer;
    cin >> t;
    for (int i = 0; i < t; i++) {
        answer = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> inputNum;
            answer += inputNum;
        }
        cout << answer << endl;
    }
    return 0;
}