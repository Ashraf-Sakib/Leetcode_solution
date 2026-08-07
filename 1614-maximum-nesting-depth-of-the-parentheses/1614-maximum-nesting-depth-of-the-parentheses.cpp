class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> st;
        int max_dpt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                max_dpt = max(max_dpt, (int)st.size());
            }
            if (s[i] == ')') {
                st.pop();
            }
        }
        return max_dpt;
    }
};