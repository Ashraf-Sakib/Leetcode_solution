class Solution {
public:
    unordered_map<int,int> memo;
    int solve(int pos, int mask, int n) {
        if (pos > n) {
            return 1;
        }
        if (memo.count(mask)) {
            return memo[mask];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int bit = 1 << (i - 1);
            if (!(mask & bit) && (i % pos == 0 || pos % i == 0)) {
                cnt += solve(pos + 1, mask | bit, n);
            }
        }
        memo[mask] = cnt;
        return cnt;
    }
    int countArrangement(int n) {
        int total = (1 << n) - 1;
        return solve(1, 0, n);
    }
};