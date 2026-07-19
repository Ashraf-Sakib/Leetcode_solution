class Solution {
public:
    int binaryGap(int n) {
        if (__builtin_popcount(n) == 1) {
            return 0;   
        }

        int lastPos = -1;
        int maxDist = 0;
        int pos = 0;

        while (n > 0) {
            if (n & 1) {
                if (lastPos != -1) {
                    maxDist = max(maxDist, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1;
            pos++;
        }
        return maxDist;
    }
};