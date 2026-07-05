class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), st = 0,  end = n -1;
        while(st < end){
            int sum = nums[st] + nums[end];
            if(sum < target){
                st++;
            }else if(sum > target){
                end--;
            }else{
                return {st+1, end +1};
            }
        }
        return {-1,-1};
    }
};