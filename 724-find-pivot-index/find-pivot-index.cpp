class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), totalsum =0, leftsum =0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        for (int idx = 0; idx < n; idx++) {
            int rightsum = totalsum - leftsum - nums[idx];
            if (leftsum == rightsum) {
                return idx;
            }
            leftsum += nums[idx];
        }
        return -1;
    }
};