class Solution {
public:
    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
        
        // 0 = land, 1 = water
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood cells for this day
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int, int>> q;

        // Start from every land cell in the first row
        for (int c = 0; c < col; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1; // mark visited
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            // Reached bottom row
            if (r == row - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= row ||
                    nc < 0 || nc >= col)
                    continue;

                if (grid[nr][nc] == 1)
                    continue;

                grid[nr][nc] = 1; // visited
                q.push({nr, nc});
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int left = 0;
        int right = cells.size();

        int ans = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canCross(mid, row, col, cells)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
