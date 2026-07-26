class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int cap, low =maxi(weights), high = weightSum(weights);
        while(low <= high){
            int mid = low + (high -low)/2;

            if(countDays(weights, mid) <= days ){
                cap =mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return cap;
    }
private:
    int countDays(vector<int>& wt, int caps){
        int days =1, load =0;
        for(int i =0; i <wt.size(); i++){
            if(load + wt[i] > caps){
                days++;
                load =wt[i];
            }else{
                load += wt[i];
            }
        }
        return days;
    }
    int maxi(vector<int>& wt){
        int mx = wt[0];
        for(int val : wt){
            if(val > mx){
                mx =val;
            }
        }
        return mx;
    }   
    int weightSum(vector<int>& wt){
        int sum =0;
        for(int val : wt){
            sum += val;
        }
        return sum;
    } 
};