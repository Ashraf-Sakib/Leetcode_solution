class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>cnt;
        for(auto val:nums){
            cnt[val]++;
        }
        for(auto x:cnt){
            if(x.second>n/2){
                return x.first;
            }
        }
        return -1;
    }
};