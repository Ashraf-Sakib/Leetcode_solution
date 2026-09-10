class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        long long type2 = 6, type3 = 6;

        for (int i = 2; i <= n; i++) {
            long long newType2 = (type2 * 3 + type3 * 2) % MOD;
            long long newType3 = (type2 * 2 + type3 * 2) % MOD;
            type2 = newType2;
            type3 = newType3;
        }

        return (int)((type2 + type3) % MOD);
    }
};