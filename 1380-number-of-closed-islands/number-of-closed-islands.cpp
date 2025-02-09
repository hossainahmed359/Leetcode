#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int n = 0, m = 0;
    bool freq[1005][1005];
    vector<pair<int, int>> move_axis = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    bool valid_axis (int i , int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    } 

    bool flag = false;
    int closed_island_count = 0;

    void DFS(int si, int sj, vector<vector<int>>& grid) {
        freq[si][sj] = true;

        for(int i = 0; i < 4; i++) {
            int ci = si + move_axis[i].first;
            int cj = sj + move_axis[i].second;

            if(!valid_axis(ci, cj))
                flag = false;

            if(valid_axis(ci, cj) && !freq[ci][cj] && grid[ci][cj] == 0)
                DFS(ci, cj, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(freq, false, sizeof(freq));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(!freq[i][j] && grid[i][j] == 0) {

                    flag = true;
                    DFS(i, j , grid);

                    if(flag) 
                        closed_island_count++;
                }
            }
        }

        return closed_island_count;
    }
};