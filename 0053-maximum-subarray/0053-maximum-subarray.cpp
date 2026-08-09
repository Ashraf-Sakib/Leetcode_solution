class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int max_val=nums[0];
        for(int i=1;i<n;i++){
            max_val=max(nums[i],max_val+nums[i]);
            ans=max(ans,max_val);
        }
        return ans;
    }
};