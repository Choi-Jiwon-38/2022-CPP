#include <iostream>
using namespace std;

int main() {
    int t, Y, M, D, allDay;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> Y >> M >> D;
        allDay = 0;
        
        for (int y = 1582; y < Y; y++) {
            if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
                allDay += 366;
            } else {
                allDay += 365;
            }
        }
        
        for (int m = 1; m < M; m++) {
            if (m == 2) {
                if (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0)) {
                    allDay += 29;
                } else {
                    allDay += 28;
                }
            } else {

                switch(m)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        allDay += 31;
                        break;

                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        allDay += 30;
                        break;
                }
            }
        }
        allDay += D - 3;
        allDay %= 7;
        cout << allDay << endl;
    }
}