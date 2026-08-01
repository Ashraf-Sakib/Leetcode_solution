class Solution {
public:
    bool canGet(vector<int>& candies, long long k, long long m) {
        long long nc = 0;
        for (auto val : candies) {
            nc += (val) / m;
        }
        return nc >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for (auto val : candies) {
            total += val;
        }
        if (k > total) {
            return 0;
        }
        long long l = 1;
        long long r = *max_element(candies.begin(), candies.end());
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            if (canGet(candies, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (int)l;
    }
};