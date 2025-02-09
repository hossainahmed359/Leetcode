#include <bits/stdc++.h>
using namespace std;

class Solution {

    int n = 0, m = 0;
    bool freq[100][100];
    vector<pair<int, int>> move_axis = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<int> area_list;

    bool valid_axis(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        return true;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid, int& area) {
        freq[si][sj] = true;
        area++;

        for (int i = 0; i < 4; i++) {
            int ci = si + move_axis[i].first;
            int cj = sj + move_axis[i].second;

            if (valid_axis(ci, cj) && !freq[ci][cj] && grid[ci][cj] == 1)
                dfs(ci, cj, grid, area);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        memset(freq, false, sizeof(freq));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!freq[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, grid, area);
                    area_list.push_back(area);
                }
            }
        }

        if (area_list.size() > 0) {
            sort(area_list.begin(), area_list.end());
            return area_list.back();
        }

        return 0;
    }
};
