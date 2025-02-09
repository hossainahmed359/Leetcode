#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int n = 0, m = 0;
    bool freq[1005][1005];
    vector<pair<int, int>> move_axis = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    bool valid_axis(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    bool flag = false;
    int sub_island_count = 0;

    void DFS(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        freq[si][sj] = true;

        if(grid1[si][sj] != grid2[si][sj])
            flag = false;

        for(int i = 0; i < 4; i++) {
            int ci = si + move_axis[i].first;
            int cj = sj + move_axis[i].second;

            if(valid_axis(ci, cj) && !freq[ci][cj] && grid2[ci][cj] == 1)
                DFS(ci, cj, grid1, grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!freq[i][j] && grid2[i][j] == 1) {
                    flag = true;
                    DFS(i, j, grid1, grid2);

                    if(flag)
                        sub_island_count++;
                }
            }
        }

        return sub_island_count;
    }
};