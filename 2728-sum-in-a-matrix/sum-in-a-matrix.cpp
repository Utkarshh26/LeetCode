class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size(),m = nums[0].size();
        vector<priority_queue<int>> pq(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pq[i].push(nums[i][j]);
            }
        }

        int ans = 0;
        for(int j = 0; j < m; j++) {
            int maxi = 0;
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, pq[i].top());
            }
            ans += maxi;
            for(int i = 0; i < n; i++) {
                pq[i].pop();
            }
        }
        return ans;
    }
};