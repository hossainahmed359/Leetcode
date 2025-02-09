#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n = 0, m = 0;
    bool freq[1005][1005];
    vector<pair<int, int>> move_axis = { {0 , -1}, {0, 1}, {-1, 0}, {1, 0} };

    int area_count = 0;

    bool valid_axis(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<char>>& grid) {
        freq[si][sj] = true;

        for(int i = 0; i < 4; i++) {
            int ci = si + move_axis[i].first;
            int cj = sj + move_axis[i].second;
            if(valid_axis(ci, cj) && !freq[ci][cj] && grid[ci][cj] == '1')
                dfs(ci, cj, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(freq, false, sizeof(freq));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!freq[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid);
                    area_count++;
                }
            }
        } 

        return area_count;
    }
};