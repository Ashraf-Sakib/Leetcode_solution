class Solution {
public:
    vector<int> adj[30005];
    vector<int> sz, down, ans;
    int n;
    void dfs1(int u, int par) {
        sz[u] = 1;
        down[u] = 0;
        for (int v : adj[u]) {
            if (v == par)
                continue;
            dfs1(v, u);
            sz[u] += sz[v];
            down[u] += down[v] + sz[v];
        }
    }
    void dfs2(int u, int par) {
        for (int v : adj[u]) {
            if (v == par)
                continue;
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v, u);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        sz.assign(n, 0);
        down.assign(n, 0);
        ans.assign(n, 0);
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (auto val : edges) {
            int u = val[0];
            int v = val[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0, -1);
        ans[0] = down[0];
        dfs2(0,- 1);
        return ans;
    }
};