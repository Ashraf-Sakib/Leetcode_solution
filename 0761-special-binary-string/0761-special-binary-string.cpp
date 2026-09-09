class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2)
            return s;

        vector<string> pieces;
        int count = 0, start = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            count += (s[i] == '1') ? 1 : -1;
            if (count == 0) {
                pieces.push_back(
                    "1" +
                    makeLargestSpecial(s.substr(start + 1, i - start - 1)) +
                    "0");
                start = i + 1;
            }
        }

        sort(pieces.begin(), pieces.end(), greater<string>());

        string result;
        for (auto& p : pieces)
            result += p;
        return result;
    }
};