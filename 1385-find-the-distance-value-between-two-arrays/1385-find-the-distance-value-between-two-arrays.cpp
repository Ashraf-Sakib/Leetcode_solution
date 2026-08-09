class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int x : arr1){
            int l=0;
            int r=arr2.size()-1;
            while(l<r){
                int mid=l+(r-l)/2;
                if(arr2[mid]<x-d) l=mid+1;
                else r=mid;
            }
            bool ok = arr2.empty() || abs(arr2[l]-x)>d;
            if(ok) ans++;
        }
        return ans;
    }
};