#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    unordered_set<long long> seen;
    seen.insert(0);

    long long sum = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        sum = (sum + x) % K;

        if (seen.count(sum)) {
            ans++;
            seen.clear();
            seen.insert(sum);
        } else {
            seen.insert(sum);
        }
    }

    cout << ans << '\n';
}
