class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    vector<vector<bool>> visited;
    int n, m;
    vector<vector<char>>* boardPtr;

    bool isValid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

    void dfs(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny) && !visited[nx][ny] &&
                (*boardPtr)[nx][ny] == 'X') {
                dfs(nx, ny);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        visited.assign(n, vector<bool>(m, false));
        boardPtr = &board;

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    dfs(i, j);
                    res++;
                }
            }
        }
        return res;
    }
};