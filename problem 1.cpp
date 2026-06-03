#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << s[j];
            }
        }
        cout << endl;
    }

    return 0;
}

