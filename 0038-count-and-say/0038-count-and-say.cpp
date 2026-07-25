class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int k = 1; k < n; k++) {
            string tmp = "";
            int i = 0, m = res.size();
            while (i < m) {
                int j = i;
                while (j < m && res[j] == res[i]) j++;
                int cnt = j - i;
                tmp += to_string(cnt) + res[i];
                i = j;
            }
            res = tmp;
        }
        return res;
    }
};