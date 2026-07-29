class Solution {
public:
    const int m=1337;
    int modPow(int base,int expo){
        int res=1;
        base=base%m;
        while(expo>0){
            if(expo%2==1){
                res=(res*base)%m;
            }
            base=(base*base)%m;
            expo=expo/2;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
        for(int i=0;i<b.size();i++){
            ans=(modPow(ans,10)*modPow(a,b[i]))%m;
        }
        return ans;
    }
};