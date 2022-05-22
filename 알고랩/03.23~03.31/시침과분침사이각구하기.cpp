#include <iostream>
using namespace std;

int main() {
    int t, h, m;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> h >> m;
        double hChim = 30.0 * h + 0.5 * m;
        double mChim = 6.0 * m;
        if (hChim > mChim) {
            if (hChim - mChim > 180) {
                cout << int(360 - (hChim - mChim)) << endl;
            } else {
                cout << int(hChim - mChim) << endl;
            }
        } else {
            if (int(mChim - hChim) > 180) {
                cout << int(360 - (mChim - hChim)) << endl;
            } else {
                cout << int(mChim - hChim) << endl;
            }
        }
    }
    return 0;
}