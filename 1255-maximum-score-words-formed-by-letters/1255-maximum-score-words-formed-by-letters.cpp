class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int available[26] = {0};
        for (char c : letters) {
            available[c - 'a']++;
        }
        
        int best = 0;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            int used[26] = {0};
            int totalScore = 0;
            bool valid = true;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (char c : words[i]) {
                        used[c - 'a']++;
                        totalScore += score[c - 'a'];
                    }
                }
            }
            
            for (int i = 0; i < 26; i++) {
                if (used[i] > available[i]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                best = max(best, totalScore);
            }
        }
        
        return best;
    }
};