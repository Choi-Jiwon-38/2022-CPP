#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, n;
    string line;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;

        line = "";

        for (int i = 0; i < n; i++) { // 맨 윗줄
            if (i == 0 || i == n / 2 || i == n - 1 ) {
                line += "+";
            } else {
                line += "-";
            }
        }
        cout << line << endl;


        for (int i = 0; i < n / 2 - 1; i++) { // 맨 윗줄 ~ 중간줄
            line = "";
            for (int j = 0; j < n; j++) {
                if (j == i + 1 ) {
                    line += "\\";
                } else if ( j == n - 2 - i) {
                    line += "/";
                } else if ( j == 0 || j == n / 2 || j == n -1 ) { 
                    line += "|";
                } else {
                    line += "*";
                }
            }
            cout << line << endl;
        }

        line = "";
        for (int i = 0; i < n; i++) { // 중간줄
            if (i == 0 || i == n - 1 ) {
                line += "+";
            } else if (i == n / 2) {
                line += "*";
            } else {
                line += "-";
            }
        }
        cout << line << endl;


        for (int i = 0; i < n / 2 - 1; i++) { // 중간줄 ~ 맨 밑줄
            line = "";
            for (int j = 0; j < n; j++) {
                if (j == n / 2 - 1 - i ) {
                    line += "/";
                } else if ( j == n / 2 + 1 + i) {
                    line += "\\";
                } else if ( j == 0 || j == n / 2 || j == n -1 ) { 
                    line += "|";
                } else {
                    line += "*";
                }
            }
            cout << line << endl;
        }

        line = "";
        for (int i = 0; i < n; i++) { // 맨 밑줄
            if (i == 0 || i == n / 2 || i == n - 1 ) {
                line += "+";
            } else {
                line += "-";
            }
        }
        cout << line << endl;
    }
}