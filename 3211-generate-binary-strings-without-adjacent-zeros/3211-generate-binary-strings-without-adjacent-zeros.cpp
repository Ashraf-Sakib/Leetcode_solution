class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        for (int m = 0; m < (1 << n); m++) {
            string s = "";
            for (int i = 0; i < n; i++) {
                char bit = ((m >> i) & 1) ? '1' : '0';
                s += bit;
            }
            bool valid = true;
            for (int j = 0; j < (int)s.length() - 1; j++) {
                if (s[j] == '0' && s[j + 1] == '0') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(s);
            }
        }
        return result;
    }
};