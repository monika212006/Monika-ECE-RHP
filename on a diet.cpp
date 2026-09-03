#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (auto &x : A) cin >> x;

    vector<long long> eaten(N, 0);

    long long sum = 0;

    for (int i = 0; i < N; i++) {

        // Remove the snack that is no longer
        // inside the most recent M days.
        if (i >= M) {
            sum -= eaten[i - M];
        }

        // Try eating today's snack.
        if (sum + A[i] <= K) {
            cout << "Yes\n";

            eaten[i] = A[i];
            sum += A[i];
        } 
        else {
            cout << "No\n";

            eaten[i] = 0;
        }
    }

    return 0;
}
