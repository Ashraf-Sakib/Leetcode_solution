class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        unordered_map<int, vector<int>> tmp; 
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            tmp[nums[i]].push_back(i);
        }
        bool flag = false;
        for (auto& [val, idxs] : tmp) {
            for (int i = 0; i + 1 < idxs.size(); i++) {
                if (abs(idxs[i] - idxs[i + 1]) <= k) {
                    flag = true;
                }
            }
        }
        return flag;
    }
};