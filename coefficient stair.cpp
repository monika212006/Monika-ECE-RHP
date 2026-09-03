#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;

void dfs(int pos, int sum) {
    // Last position
    if (pos == N) {
        if (sum == K) {
            for (int i = 0; i < N; i++) {
                cout << A[i] << (i + 1 == N ? '\n' : ' ');
            }
        }
        return;
    }

    // Coefficient of A[pos] is pos + 1
    int weight = pos + 1;

    // Try values in increasing order
    for (int x = 0; sum + weight * x <= K; x++) {
        A[pos] = x;
        dfs(pos + 1, sum + weight * x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    A.resize(N);

    dfs(0, 0);

    return 0;
}
