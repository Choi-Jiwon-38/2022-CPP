#include <iostream>
using namespace std;

int main() {
    int t, answer;
    char inputWord[257] = "";

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> inputWord;
        answer = 1;
        for (int i = 0; i < sizeof(inputWord); i++) {
            
            if (inputWord[i] == '\0') {
                break;
            }

            if (i == 0) {
                if ( (33 <= inputWord[i] && inputWord[i] <= 64) || (91 <= inputWord[i] && inputWord[i] <= 94) || (123 <= inputWord[i] && inputWord[i] <= 126) || inputWord[i] == 96) {
                    answer = 0;
                    break;
                }
            } else {
                if ( (33 <= inputWord[i] && inputWord[i] <= 47) || (58 <= inputWord[i] && inputWord[i] <= 64) || (91 <= inputWord[i] && inputWord[i] <= 94) || (123 <= inputWord[i] && inputWord[i] <= 126) || inputWord[i] == 96) {
                    answer = 0;
                    break;
                }
            }
        }
        cout << answer << endl;
    }
}