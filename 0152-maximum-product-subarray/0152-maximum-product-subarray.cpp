class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int max_p = nums[0];
        int min_p = nums[0];
        for(int i = 1; i < n; i++){
            int cur = nums[i];
            int cand1 = cur;
            int cand2 = cur * max_p;
            int cand3 = cur * min_p;
            
            max_p = max({cand1, cand2, cand3});
            min_p = min({cand1, cand2, cand3});
            
            ans = max(ans, max_p);
        }
        return ans;
    }
};