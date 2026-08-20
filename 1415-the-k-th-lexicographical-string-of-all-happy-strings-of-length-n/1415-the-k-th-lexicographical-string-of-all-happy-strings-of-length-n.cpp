typedef long long ll;
class Solution {
public:
    string getHappyString(int n, int k) {
        ll total = 3LL << (n - 1);
        if (k > total)
            return "";

        string ch = "abc";
        string res = "";
        ll k1 = k - 1;
        ll block = 1LL << (n - 1);

        int first = k1 / block;
        res += ch[first];
        k1 %= block;

        char last = ch[first];
        block /= 2;

        for (int i = 1; i < n; i++) {
            string opts = "";
            for (char c : ch)
                if (c != last)
                    opts += c;

            int idx = (block == 0) ? 0 : k1 / block;
            res += opts[idx];
            last = opts[idx];

            if (block > 0)
                k1 %= block;
            block /= 2;
        }

        return res;
    }
};