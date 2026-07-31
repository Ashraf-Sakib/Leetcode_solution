class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int total=1<<n;
        set<vector<int>>sub;
        for(int mask=0;mask<total;mask++){
            vector<int>tmp;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    tmp.push_back(nums[i]);
                }
            }
            sub.insert(tmp);
        }
         vector<vector<int>>result(sub.begin(),sub.end());
         return result;
    }
};