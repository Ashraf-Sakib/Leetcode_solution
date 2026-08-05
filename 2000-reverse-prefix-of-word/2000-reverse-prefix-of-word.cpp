class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        stack<char>st;
        int idx=word.find(ch);
        if(idx==-1){
            return word;
        }
        for(int i=0;i<=idx;i++){
            st.push(word[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
         ans += word.substr(idx + 1);
         return ans;
    }
};