class Solution {
public:
    bool canRepair(vector<int>& ranks, int cars, long long t) {
        long long count = 0;
        for (int rank : ranks) {
            count += (long long)sqrt((double)t / rank);
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r =
            (long long)(*min_element(ranks.begin(), ranks.end())) * cars * cars;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (canRepair(ranks, cars, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};