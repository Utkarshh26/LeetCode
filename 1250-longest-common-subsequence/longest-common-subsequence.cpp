class Solution {
private:
    int helper(int id1, int id2,vector<vector<int>>&dp,const string& txt1,const string& txt2){
        if(id1 <0 ||id2 <0){
            return 0;
        }
        if(dp[id1][id2] !=-1){
            return dp[id1][id2];
        }
        if(txt1[id1]== txt2[id2]){
            return dp[id1][id2] = 1 +helper(id1-1,id2-1,dp,txt1,txt2);
        }
        return dp[id1][id2] =max(helper(id1-1,id2,dp,txt1,txt2),helper(id1,id2-1,dp,txt1,txt2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size(),m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,dp,text1,text2);
    }
};