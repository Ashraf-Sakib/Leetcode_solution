class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for (auto ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        int total = 0;
        for (int i = 0; i < 26; i++) {
            int cost = i / 8 + 1;
            total += freq[i] * cost;
        }
        return total;
    }
};