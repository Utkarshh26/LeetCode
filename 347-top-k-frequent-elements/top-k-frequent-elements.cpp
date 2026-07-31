class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) != freq.end()) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }
        vector<int> ans;
        while (k--) {
            int mxFreq = 0, ele =0;

            for (auto &it : freq) {
                if (it.second > mxFreq) {
                    mxFreq = it.second;
                    ele = it.first;
                }
            }
            ans.push_back(ele);
            freq[ele] = 0;
        }
        return ans;
    }
};