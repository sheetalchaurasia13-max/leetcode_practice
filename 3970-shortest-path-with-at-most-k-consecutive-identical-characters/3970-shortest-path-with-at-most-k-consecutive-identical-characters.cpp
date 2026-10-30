class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Build adjacency list: adj[u] = list of pairs {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        
        // Priority queue stores tuples of: {current_weight, current_node, consecutive_count}
        // We use a min-heap, so we need greater comparator or negative weights, 
        // but standard pair/tuple comparison works if weight is first.
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        
        // dist[node][count] stores the minimum weight to reach 'node' 
        // with 'count' consecutive identical characters ending at this node.
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        
        // Start at node 0 with count 1 (since labels[0] is the first character)
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        
        while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();
            
            if (w > dist[u][count]) continue;
            if (u == n - 1) return w;
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                
                if (next_count <= k) {
                    if (w + weight < dist[v][next_count]) {
                        dist[v][next_count] = w + weight;
                        pq.push({w + weight, v, next_count});
                    }
                }
            }
        }
        
        return -1;
    }
};