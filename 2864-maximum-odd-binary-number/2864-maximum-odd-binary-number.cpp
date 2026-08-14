class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0;
        //string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                cnt1++;
        }
        int cnt0 = s.length() - cnt1;

        string res = string(cnt1 - 1, '1') + string(cnt0, '0') + "1";
        return res;
    }
};