class Solution {
private:
    int helper(int l,int r,vector<vector<int>>& dp, const string& s) {
        if (l >r){
            return 0;
        }
        if (l== r){
            return 1;
        }
        if (dp[l][r]!= -1){
            return dp[l][r];
        }
            
        if (s[l] == s[r]) {
            return dp[l][r] =2 + helper(l+1, r-1,dp,s);
        }
        return dp[l][r] = max(helper(l+1,r,dp,s),helper(l,r-1,dp,s));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n= s.size();
        vector<vector<int>> dp( n,vector<int>(n, -1));
        return helper(0, n - 1, dp, s);
    }
};