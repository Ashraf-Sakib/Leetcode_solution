class Solution {
public:
    vector<int> memo;
    int helper(int x) {
        if (x == 1) {
            return 0;
        }
        if (memo[x] != -1) {
            return memo[x];
        }
        int best = INT_MAX;
        for (int a = 1; a < x; a++) {
            int b = x - a;
            int curr = a * b + helper(a) + helper(b);
            best = min(best, curr);
        }
        memo[x] = best;
        return best;
    }
    int minCost(int n) {
        memo.assign(n + 1, -1);
        return helper(n);
    }
};