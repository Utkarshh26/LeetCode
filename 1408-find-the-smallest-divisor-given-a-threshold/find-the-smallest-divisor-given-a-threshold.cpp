class Solution {
private:
    int maxi(vector<int>& nums){
        int mx =nums[0];
        for(int val : nums){
            if(val > mx){
                mx = val;
            }
        }
        return mx;
    }    
    int sum(vector<int>& nums, int divisor){
        int sum =0;
        for(int i =0; i <nums.size(); i++){
            sum += ceil((double)nums[i]/divisor);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int divi, low = 1, high = maxi(nums);
        while(low <= high){
            int mid = low + (high -low)/2;
            if(sum(nums, mid) <= threshold){
                divi =mid;
                high= mid -1;
            }else{
                low =mid +1;
            }
        }
        return divi;
    }
};