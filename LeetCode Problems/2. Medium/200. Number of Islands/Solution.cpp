#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void bfs(
        vector<vector<char>>& grid,
        vector<pair<int, int>>& delta,
        int start_x, int start_y,
        int m, int n
    )
    {
        queue<pair<int, int>> q;

        grid[start_x][start_y] = '0';
        q.push({start_x, start_y});

        while (!q.empty()) {
            auto [sx, sy] = q.front();

            q.pop();

            for (auto [dx, dy] : delta) {
                int x = sx + dx, y = sy + dy;

                if (x < 0 || x > m - 1 || y < 0 || y > n - 1 || grid[x][y] == '0') 
                    continue;

                q.push({x, y});
                grid[x][y] = '0';
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;

                bfs(grid, delta, i, j, m, n);
                ++result;
            }
        }

        return result;
    }
};
