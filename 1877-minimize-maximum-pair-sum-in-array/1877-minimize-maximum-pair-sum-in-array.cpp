class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            ans = max(ans, sum);
            i++;
            j--;
        }
        return ans;
    }
};