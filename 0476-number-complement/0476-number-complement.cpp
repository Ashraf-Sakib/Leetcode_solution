class Solution {
public:
    int findComplement(int num) {
        int tmp=num;
        int m=0;
        while(tmp>0){
            m=(m<<1)|1;
            tmp>>=1;
        }
        return num^m;
    }
};