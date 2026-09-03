#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, Q;
    cin >> A >> B >> Q;

    vector<long long> s(A), t(B);

    for (auto &x : s) cin >> x;
    for (auto &x : t) cin >> x;

    while (Q--) {
        long long x;
        cin >> x;

        // Add boundaries so lower_bound always has
        // an element on both sides.
        s.insert(s.begin(), -4e18);
        s.push_back(4e18);

        t.insert(t.begin(), -4e18);
        t.push_back(4e18);

        // First shrine >= x
        auto si = lower_bound(s.begin(), s.end(), x);

        // First temple >= x
        auto ti = lower_bound(t.begin(), t.end(), x);

        long long sr = *si;       // shrine to right
        long long sl = *(si - 1); // shrine to left

        long long tr = *ti;       // temple to right
        long long tl = *(ti - 1); // temple to left

        long long ans = LLONG_MAX;

        // 1. Shrine left, Temple left
        ans = min(ans, x - sl + x - tl);

        // 2. Shrine right, Temple right
        ans = min(ans, sr - x + tr - x);

        // 3. Shrine left, Temple right
        ans = min(ans,
                  min(x - sl, tr - x) * 2 +
                  max(x - sl, tr - x));

        // 4. Shrine right, Temple left
        ans = min(ans,
                  min(sr - x, x - tl) * 2 +
                  max(sr - x, x - tl));

        cout << ans << '\n';
    }

    return 0;
}
