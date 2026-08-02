class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1){
            return 0;
        }
        int left =0, count =0;
        long long prd =1;

        for(int i=0; i<nums.size(); i++){
            prd *= nums[i];
            while(prd >= k){
                prd /= nums[left];
                left++;
            }
            count += i -left +1;
        }
        return count;
    }
};