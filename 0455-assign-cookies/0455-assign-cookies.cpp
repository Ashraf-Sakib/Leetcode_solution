class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c = g.size();
        int b = s.size();
        int i = 0, j = 0;
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < c && j < b) {
            if (s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};