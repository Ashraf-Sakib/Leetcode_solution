class Solution {
public:
    bool helper(vector<int>& quantities, int n, int mx) {
        int products = 0;
        for (auto val : quantities) {
            products += (val + mx - 1) / mx;
        }
        return n >= products;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(quantities, n, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};