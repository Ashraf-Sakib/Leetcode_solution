class Solution {
public:
    typedef pair<int, int> pii;
    int n, m;
    bool visited[200][200];
    vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
    void dfs(int x, int y, vector<vector<char>>& board) {
        visited[x][y] = true;
        for (pii p : path) {
            int nx = x + p.first;
            int ny = y + p.second;
            if (isValid(nx, ny) && !visited[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool boundary = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
                if (boundary && isValid(i, j) && !visited[i][j] &&
                    board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};