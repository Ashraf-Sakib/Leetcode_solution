class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans;
        int n=s.length();
        stack<int>st;
        for(int i=0;i<=n;i++){
            st.push(i);
            if(i==n||s[i]=='I'){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};