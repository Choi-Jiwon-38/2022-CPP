#include <iostream>
using namespace std;

int main() {
    int t, n, n_copy, n_copypy, count, isAnswer, addNum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        n_copypy = n_copy = n;
        
        count = 0;
        isAnswer = 0;

        while (n_copy > 0) {
            n_copy /= 10;
            count++;
        }
        
        while (n > 0) {
            addNum = 1;
            for (int i = 0; i < count; i++) {
                addNum *= (n % 10); 
            }
            isAnswer += addNum;
            n /= 10;
        }

        if (isAnswer == n_copypy) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}