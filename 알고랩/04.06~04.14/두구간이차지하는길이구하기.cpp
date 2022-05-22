#include <iostream>
using namespace std;

int main() {
    int t, a, b, c, d, length, space;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        cin >> a >> b >> c >> d;
        length = (b - a) + (d - c);
        if ( b < c || d < a ) { // 두 구간이 겹치지 않는 경우
            space = 0;
        } else if ( a <= c ) { // [a, b]가 [c, d]보다 왼쪽에 있는 경우
            if ( b >= d ) {
                space = d - c;
            } else {
                space = b - c;
            }
        } else if ( c <= a ) { // [c, d]가 [a, b]보다 왼쪽에 있는 경우
            if ( d >= b ) {
                space = b - a;
            } else {
                space = d - a;
            }
        }
        length -= space;
        cout << space << " " << length << endl;
    }
}