class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int idx =0; idx < n; idx++){
            int leftsum =0, rightsum =0;
            for(int i =0; i< idx; i++){
                leftsum += nums[i];
            }

            for(int i = idx+1; i <n; i++){
                rightsum += nums[i];
            }
            if(leftsum == rightsum){
                return idx;
            }
        }
        return -1;
    }
};