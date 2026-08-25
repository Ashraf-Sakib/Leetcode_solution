class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;

    int id(int r, int c, int t) { return (r * n + c) * 4 + t; }

    void dfs(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs(v);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        int totalNodes = n * n * 4;
        adj.assign(totalNodes, vector<int>());
        visited.assign(totalNodes, false);

        auto addEdge = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                char ch = grid[r][c];
                int top = id(r, c, 0), right = id(r, c, 1),
                    bottom = id(r, c, 2), left = id(r, c, 3);

                if (ch == '/') {
                    addEdge(top, left);
                    addEdge(right, bottom);
                } else if (ch == '\\') {
                    addEdge(top, right);
                    addEdge(left, bottom);
                } else {
                    addEdge(top, right);
                    addEdge(right, bottom);
                    addEdge(bottom, left);
                }

                if (c + 1 < n) {
                    addEdge(right, id(r, c + 1, 3));
                }
                if (r + 1 < n) {
                    addEdge(bottom, id(r + 1, c, 0));
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < totalNodes; i++) {
            if (!visited[i]) {
                dfs(i);
                regions++;
            }
        }
        return regions;
    }
};