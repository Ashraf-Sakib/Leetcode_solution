class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + travel[i - 1];
        }
        
        int totalTime = 0;
        unordered_map<char, int> lastIndex;
        
        for (int i = 0; i < n; i++) {
            totalTime += garbage[i].size();
            for (char c : garbage[i]) {
                lastIndex[c] = i;
            }
        }
        
        for (auto& [type, idx] : lastIndex) {
            totalTime += prefix[idx];
        }
        
        return totalTime;
    }
};