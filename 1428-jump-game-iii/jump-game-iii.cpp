class Solution {
    vector<bool> visited;
private:
    bool helper(vector<int>&arr, int idx) {
        if (arr[idx] ==0){
            return true;
        }
        if (visited[idx]){
            return false;
        }
        visited[idx]= true;
        
        if (idx+ arr[idx]< arr.size()){
            if (helper(arr, idx+ arr[idx])){
                return true;
            }
        }
        if (idx -arr[idx] >=0){
            if (helper(arr,idx -arr[idx])){
                return true;
            }
        }
        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        visited = vector<bool>(arr.size(),false);
        return helper(arr,start);
    }
};