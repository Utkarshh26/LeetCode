class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
     int maxi = 0, mini = 0, n = nums.size();
     for(int i = 0; i < n; i++){
        if(nums[i] > nums[maxi]){
            maxi = i;
        }
        if(nums[i] < nums[mini]){
            mini = i;
        }
     }  
        int left = max(mini, maxi)+1;
        int right = n -min(mini, maxi);
        int both = min(mini, maxi)+1+(n-max(maxi, mini));
        return min(left, min(right, both));
     
    }
};