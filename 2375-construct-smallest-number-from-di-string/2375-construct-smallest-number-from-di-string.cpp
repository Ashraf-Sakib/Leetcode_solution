class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res;
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            st.push(i + 1);
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    res += char('0' + st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};