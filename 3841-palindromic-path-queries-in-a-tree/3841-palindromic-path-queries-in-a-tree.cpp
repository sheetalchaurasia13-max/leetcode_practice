#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    
    // Segment Tree for point updates and range XOR queries
    vector<int> tree;
    int N;

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ 
               query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int dfs_heavy(int v, int p, int d) {
        parent[v] = p;
        depth[v] = d;
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v]) {
            if (c != p) {
                int c_size = dfs_heavy(c, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = ++cur_pos;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(c, c);
            }
        }
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= query_tree(1, 1, N, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= query_tree(1, 1, N, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        N = n;
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;

        dfs_heavy(0, -1, 0);
        decompose(0, 0);

        tree.assign(4 * n, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            update_tree(1, 1, n, pos[i], mask);
        }

        vector<bool> answer;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int mask = 1 << (c - 'a');
                update_tree(1, 1, n, pos[u], mask);
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                int path_mask = query_path(u, v);
                bool is_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};
