class Solution {
public:
    typedef pair<int, int> pii;
    bool visited[300][300];
    vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    bool isValid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
    int dfs(int x, int y, vector<vector<int>>& grid) {
        visited[x][y] = true;
        int area = 1;
        for (pii p : path) {
            int nx = x + p.first;
            int ny = y + p.second;
            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 1) {

                 area += dfs(nx, ny, grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isValid(i, j) && !visited[i][j] && grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};