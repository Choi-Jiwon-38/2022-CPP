// library 함수 사용 실습 + command line arguments
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "usage: ./dice n\n";
        return -1;
    }
    int seedNum;
    seedNum = atoi(argv[1]);
    for (int j = 0; j < 10; j++) {
        srand(seedNum + j);
        int dice = rand() % 6 + 1;
        cout << dice << " ";
    } 
    cout << endl;
}