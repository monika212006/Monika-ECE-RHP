#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int lowerMask = 0;
    int upperMask = 0;

    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            lowerMask |= (1 << (ch - 'a'));
        }
        else if (ch >= 'A' && ch <= 'Z') {
            upperMask |= (1 << (ch - 'A'));
        }
    }

    int allBits = (1 << 26) - 1;

    if (lowerMask == allBits && upperMask == allBits)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
