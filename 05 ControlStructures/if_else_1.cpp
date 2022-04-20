#include <iostream>
using namespace std;

// if else matching

int main() {
    int score = 85;

    // if (score > 80) 
    //     if (score > 90)
    //         cout << "당신의 학점은 A입니다.";
    //     else
    //         cout << "당신의 학점은 B입니다.";

    if (score > 80)
    {
        if (score > 90)
            cout << "당신의 학점은 A입니다.\n"; 
    }
    else
        cout << "당신의 학점은 A나 B가 아닙니다.\n";
}