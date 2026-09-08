#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000007;

int n, k;
ll a[MAXN], b[MAXN], ans;

struct DSU {
    ll fa[MAXN], sz[MAXN], L[MAXN], R[MAXN];

    void init(int n) {
        iota(fa + 1, fa + n + 1, 1);
        fill(sz + 1, sz + n + 1, 1);
        iota(L + 1, L + n + 1, 1);
        iota(R + 1, R + n + 1, 1);
    }

    int find(int x) {
        while (x != fa[x]) {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (sz[x] > sz[y])
            swap(x, y);

        fa[x] = y;
        sz[y] += sz[x];

        L[y] = min(L[y], L[x]);
        R[y] = max(R[y], R[x]);
    }
} dsu;

bool check(ll x) {
    dsu.init(4 * n);

    // Process energy levels from right to left.
    for (ll i = 2 * n; i >= 1; --i) {

        ll cur = b[i];
        ll p = i;

        // Number of operations spent by drones originating at i.
        ll used = 0;

        while (cur > 1) {

            // Merge p and p+1, effectively skipping an already
            // processed/occupied segment.
            dsu.merge(p, p + 1);

            ll to = dsu.R[dsu.find(p)];

            used += to - p;
            p = to;

            if (used > x)
                break;

            --cur;
        }

        // If there were drones at i, merge the final position too.
        if (b[i])
            dsu.merge(p, p + 1);

        // We still have more than k drones at this value,
        // so x operations aren't enough.
        if (cur > k)
            return false;
    }

    return true;
}

ll solve() {
    ll lo = 0;
    ll hi = 3 * n;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k;

        ans = 0;

        // Clear frequency array.
        fill(b, b + 2 * n + 2, 0);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++b[a[i]];
        }

        cout << solve() << '\n';
    }

    return 0;
}
