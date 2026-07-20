class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int a_mask=0;
        for(char ch:allowed){
            a_mask|=(1<<(ch-'a'));
        }
        int cnt=0;
        for(string word:words){
            int w_mask=0;
            for(char c:word){
                w_mask|=(1<<(c-'a'));
            }
            if((w_mask & a_mask)==w_mask)cnt++;
        }
        return cnt;
    }
};