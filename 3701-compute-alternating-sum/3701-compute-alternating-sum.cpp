class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 0;
        int ans2 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans1 += nums[i];
            } else {
                ans2 += nums[i];
            }
        }
        return ans1 - ans2;
    }
};