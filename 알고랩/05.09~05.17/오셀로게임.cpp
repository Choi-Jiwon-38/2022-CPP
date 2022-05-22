#include <iostream>
using namespace std;

int main() {
    int t;
    char game[8][8];
    cin >> t;
    for (int i = 0; i < t; i++) {
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                game[i][j] = '+';
            }
            game[4 - 1][4 - 1] = 'O'; game[5 - 1][5 - 1] = 'O';
            game[4 - 1][5 - 1] = 'X'; game[5 - 1][4 - 1] = 'X'; 
        }
        

        // 디버깅용 코드
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << game[i][j] << " ";
            }
            cout << endl;
        }
    }
}