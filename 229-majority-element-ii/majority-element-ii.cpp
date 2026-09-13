class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ele = nums[0], count = 0, n = nums.size();
        vector<int> freq;
        for (int i = 0; i < n; i++) {
            if (ele == nums[i]) {
                count++;
            } else if (ele != nums[i]) {
                if (count > n / 3) {
                    freq.push_back(ele);
                }
                ele = nums[i];
                count = 1;
            }
        }
        if (count > n / 3) {
            freq.push_back(ele);
        }
        return freq;
    }
};