#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> cnt(K + 1, 0);

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    int mx = 0;

    for (int i = 1; i <= K; i++) {
        mx = max(mx, cnt[i]);
    }

    int ans = 0;

    for (int i = 1; i <= K; i++) {
        if (cnt[i] == mx) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
