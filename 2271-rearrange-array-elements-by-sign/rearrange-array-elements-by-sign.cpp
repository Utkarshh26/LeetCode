class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> posArr;
        vector<int> negArr;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                posArr.emplace_back(nums[i]);
            }else{
                negArr.emplace_back(nums[i]);
            }
        }
        
        int idx =0;
        for(int i =0; i < n; i+=2){
            nums[i] = posArr[idx++];
        }
        idx =0;
        for(int i =1; i < n; i+=2){
            nums[i] = negArr[idx++];
        }
        return nums;
    }
};