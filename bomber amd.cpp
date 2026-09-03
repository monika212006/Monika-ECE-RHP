#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for (auto &row : S) cin >> row;

    // Determine which rows and columns contain bombs
    vector<bool> rowBomb(H, false);
    vector<bool> colBomb(W, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                rowBomb[i] = true;
                colBomb[j] = true;
            }
        }
    }

    // dist[i][j] = distance from nearest safe cell
    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue<pair<int, int>> q;

    // All safe cells are BFS starting points
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            if (S[i][j] == '.' &&
                !rowBomb[i] &&
                !colBomb[j]) {

                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    // Multi-source BFS
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || ni >= H || nj < 0 || nj >= W)
                continue;

            if (S[ni][nj] == '#')
                continue;

            if (dist[ni][nj] != -1)
                continue;

            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});
        }
    }

    long long ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.' && dist[i][j] <= K) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
