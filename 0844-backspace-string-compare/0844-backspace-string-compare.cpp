class Solution {
public:
    string helper(string s) {
        string ans;
        stack<char> st;
        for (auto ch : s) {
            if (ch != '#') {
                st.push(ch);
            } else {
                if (!st.empty()) st.pop();
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) { return helper(s) == helper(t); }
};