class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int peakIdx = 0 ;
       for (int i = 1; i< nums.size(); i++){
        if (nums[i] > nums[peakIdx]){
            peakIdx = i;
        }
       } 
       return peakIdx;
    }
};