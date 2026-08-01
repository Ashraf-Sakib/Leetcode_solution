class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int pieces = 1;
        long long curr = 0;
        for (int x : nums) {
            if (curr + x > maxSum) {
                pieces++;
                curr = x;
                if (pieces > k) return false;
            } else {
                curr += x;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int x : nums) {
            lo = max(lo, (long long)x); 
            hi += x;                    
        }

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid))
                hi = mid;      
            else
                lo = mid + 1;  
        }
        return (int)lo;
    }
};