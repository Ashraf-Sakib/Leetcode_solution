class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            hrs += ceil((double)piles[i] / k);
        }
        return hrs <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canFinish(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};