#include <iostream>
using namespace std;

int main() {
    int t; // 테스트 케이스의 개수
    int n; // 마방진의 크기를 나타내는 자연수 (1 <= n <= 49)
    int cnt; // 마방진에 넣는 수
    int x, y;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cnt = 0;
        cin >> n;
        int arr[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
        
        x = 0; y = n/2; // 마방진 첫 좌표 설정
        
        while (cnt < n * n) {
            cnt++;
            
            if (x == -1) { // n*n 크기를 벗어났을 때
                x = n - 1;  
            } 
            
            if (y == n) { // n*n 크기를 벗어났을 때
                y = 0;
            }
            
            arr[x][y] = cnt;
            
            if (cnt % n == 0) {
                x++;
                continue;
            }
            
            x--; y++;
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}