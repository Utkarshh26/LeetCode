class Solution {
    vector<int> dp;
private:
    bool helper(vector<int>& nums, int idx) {
        if (idx == nums.size() - 1) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < nums.size()) {
                if (helper(nums, idx + i)) {
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
public:
    bool canJump(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1);
        return helper(nums, 0);
    }
};