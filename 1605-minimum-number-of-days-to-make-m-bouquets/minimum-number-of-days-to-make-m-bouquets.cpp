class Solution {
private:
    int maxi(vector<int>& arr) {
        int mx = arr[0];
        for (int val : arr) {
            if (mx < val) {
                mx = val;
            }
        }
        return mx;
    }
    int mini(vector<int>& arr) {
        int mn = arr[0];
        for (int val : arr) {
            if (mn > val) {
                mn = val;
            }
        }
        return mn;
    }

    int bouqet(vector<int>& arr, int days, int k){
        int totalBouq =0, count =0;
        for(int i =0; i< arr.size(); i++){
            if(days >= arr[i] ){
               count++;
            }else{
                totalBouq += count/k;
                count =0;
            }
        }
        totalBouq+= count/k;
        return totalBouq;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int days = -1, low = mini(bloomDay),high = maxi(bloomDay);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bouqet(bloomDay, mid,k) >= m) {
                days = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return days;
    }
};