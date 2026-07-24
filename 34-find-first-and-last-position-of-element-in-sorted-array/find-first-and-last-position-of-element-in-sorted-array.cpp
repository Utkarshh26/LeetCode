class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool first) {
        int st = 0, end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (first) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        if (first == -1){
            return {-1, -1};
        }
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};