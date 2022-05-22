#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define TARGET 'e'

int main(int argc, char *argv[]) {
    if (argc < 2) { cout << "one command argument needed\n"; }
    int n = strlen(argv[1]);
    char *a = new char[n * 2 + 3];
    if (!a) { cout << "allocation failed.\n"; return -1; }
    a[0] = '!';
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (argv[1][i] == 'e') {
            a[count] = argv[1][i];
            a[count + 1] = argv[1][i];
            count += 2;
        } else {
            a[count] = argv[1][i];
            count += 1;
        }
    }

    a[count] = '.';
    cout << a << endl;

    string s = "!";
    s += argv[1];
    s += ".";
    int pos = 0;
    
    while (s.find('e', pos) != -1) {    
        pos = s.find('e', pos);
        s.insert(pos, "e");
        pos += 2;
    }

    cout << s << endl;
}

