class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
        int bal = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                bal++;
            }
            if (s[i] == 'R') {
                bal--;
            }
            if (bal == 0) {
                ans++;
            }
        }
        return ans;
    }
};