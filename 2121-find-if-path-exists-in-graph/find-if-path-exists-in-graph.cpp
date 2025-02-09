#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<vector<int>> adj_list;
    bool freq[10000005];

    void dfs(int node) {
        freq[node] = true;

        vector<int> connected_nodes = adj_list[node];
        for (int x : connected_nodes) {
            if (!freq[x])
                dfs(x);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj_list.resize(n);
        memset(freq, false, sizeof(freq));

        for (int i = 0; i < edges.size(); i++) {
            vector<int> vec = edges[i];

            int first = vec[0];
            int second = vec[1];

            adj_list[first].push_back(second);
            adj_list[second].push_back(first);
        }

        dfs(source);

        return freq[destination];

    }
};