class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int n = apple.size();
        int m = capacity.size();
        int box = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += apple[i];
        }
        for (int i = 0; i < m; i++) {
            if (total <= 0)
                break;
            total -= capacity[i];
            box++;
        }
        return box;
    }
};