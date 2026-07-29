class Solution {
public:
    typedef long long ll;
    const int MOD=1e9+7;
    ll modPow(ll base,ll expo,ll m){
        ll res=1;
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
    int countGoodNumbers(long long n) {
        ll ce=(n+1)/2;
        ll co=n/2;
        ll ans=(modPow(5,ce,MOD)*modPow(4,co,MOD))%MOD;
        return (int) ans;
    }
};