class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), prf = 1, suf = 1,maxPrd = INT_MIN;
        for(int i =0; i< n; i++){
            if(prf == 0){
                prf = 1;
            }
            if(suf == 0){
                suf =1;
            }
            prf *= nums[i];
            suf *= nums[n -i-1];
            maxPrd = max(max(prf, suf),maxPrd);
        }
        return maxPrd;
    }
};