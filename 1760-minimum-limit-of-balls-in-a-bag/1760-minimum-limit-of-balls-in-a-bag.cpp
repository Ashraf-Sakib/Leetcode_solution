class Solution {
public:
    bool canDivide(vector<int>&nums,int maxOperations,int p){
        int penalty=0;
        for(auto val:nums){
            penalty+=((val-1)/p);
        }
        return penalty<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(canDivide(nums,maxOperations,mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};