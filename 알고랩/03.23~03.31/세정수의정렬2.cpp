#include <iostream>
using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        if (a <= b) {
            if (b <= c) {
                cout << a << " " << b << " " << c << endl;
            } else {
                if (a <= c) {
                    cout << a << " " << c << " " << b << endl;
                } else {
                    cout << c << " " << a << " " << b << endl;
                }
            }
        } else {
            if (c <= b) {
                cout << c << " " << b << " " << a << endl;
            } else {
                if (a <= c) {
                    cout << b << " " << a << " " << c << endl;
                } else {
                    cout << b << " " << c << " " << a << endl;
                }
            }
        }
    }
    return 0;
}
