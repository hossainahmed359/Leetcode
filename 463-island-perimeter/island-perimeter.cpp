#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int row, column;
    bool freq[1005][1005];
    vector<pair<int, int>> move_axis = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool valid_axis(int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= column)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid, int& parameter) {
        freq[si][sj] = true;

        for (int i = 0; i < 4; i++) {
            int ci = si + move_axis[i].first;
            int cj = sj + move_axis[i].second;

            if (
                (valid_axis(ci, cj) == true && grid[ci][cj] == 0) ||
                valid_axis(ci, cj) == false
                // || 
                // (ci == -1 || ci == row || cj == -1 || cj == column)
            )
                parameter++;

            if (valid_axis(ci, cj) == true && freq[ci][cj] == false &&
                grid[ci][cj] == 1)
                dfs(ci, cj, grid, parameter);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        column = grid[0].size();
        memset(freq, false, sizeof(freq));

        int parameter = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (freq[i][j] == false && grid[i][j] == 1) {
                    dfs(i, j, grid, parameter);
                    break;
                }
            }
        }

        return parameter;
    }
};