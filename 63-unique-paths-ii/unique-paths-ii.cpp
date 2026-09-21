class Solution {
    vector<vector<int>> dp;
private:    
    int helper(vector<vector<int>>& grid,int row,int col){
        int m=grid.size()-1, n =grid[0].size()-1;
        if((row == m&& col ==n) && grid[row][col] ==0){
            return 1;
        }
        if(row >m || col>n){
            return 0;
        }
        if(grid[row][col] ==1){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = helper(grid,row+1,col);
        int right = helper(grid,row,col+1);
        return dp[row][col]= down+ right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size(), cols =obstacleGrid[0].size();
        dp.assign(rows, vector<int>(cols,-1));
        return helper(obstacleGrid,0,0);
    }
};