class Solution {
private:
    int maxi(vector<int>& arr){
        int n = arr.size(), ans = arr[0];
        for(int i = 1; i <n; i++){
            if(ans < arr[i]){
                ans = arr[i];
            }
        }
        return ans;
    }    
    long long time(vector<int>& arr, int k){
        long long time =0;
        for(int piles : arr){
            time +=ceil((double)piles/k);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k, low = 1, high =maxi(piles);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(time(piles, mid) <= h){
                k = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return k;
    }
};