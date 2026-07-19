class Solution {
public:
    static bool helper(int a,int b){
        int cnt1=__builtin_popcount(a);
        int cnt2=__builtin_popcount(b);
        if(cnt1!=cnt2){
            return cnt1<cnt2;
        }
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),helper);
        return arr;
    }
};