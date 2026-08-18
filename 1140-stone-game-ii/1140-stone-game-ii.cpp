class Solution {
public:
    int n;
    vector<int> suf;
    int dp[105][105];

    int solve(int i, int m) {
        if (i >= n)
            return 0;
        if (i + 2 * m >= n)
            return suf[i];
        if (dp[i][m] != -1)
            return dp[i][m];
        int best = 0;
        for (int x = 1; x <= 2 * m; x++) {
            int take =
                suf[i] - suf[i + x] + (suf[i + x] - solve(i + x, max(m, x)));
            best = max(best, take);
        }
        return dp[i][m] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suf.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] + piles[i];
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};