class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3;
        int ans = 0;

        int r = 3 * n - 1;
        for (int i = 0; i < n; i++) {
            ans += piles[r - 1];
            r = r - 2;
        }
        return ans;
    }
};