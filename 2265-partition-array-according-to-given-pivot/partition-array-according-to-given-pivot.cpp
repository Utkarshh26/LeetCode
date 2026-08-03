class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;
        for (int x : nums) {
            if (x < pivot){
                less++;
            }else if (x == pivot){
                equal++;
            }
        }

        vector<int> ans(nums.size());
        int low = 0, mid = less,  high = less + equal;
        for (int x : nums) {
            if (x < pivot){
                ans[low++] = x;
            }else if (x == pivot){
                ans[mid++] = x;
            }else{
                ans[high++] = x;
            }       
        }

        return ans;
    }
};