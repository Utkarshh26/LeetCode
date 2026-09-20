class Solution {
private:
    int helper(string& s,int idx,vector<int>& dp) {
        if (idx== s.size()) {
            return 1;
        }
        if (s[idx] =='0') {
            return 0;
        }
        if (dp[idx] !=-1) {
            return dp[idx];
        }
        
        int ways= helper(s,idx+1, dp);
        if (idx+ 1 <s.length()) {
            if (s[idx] =='1' ||(s[idx]=='2' && s[idx+1] <='6')) {
                ways += helper(s,idx+ 2, dp);
            }
        }
        return dp[idx] = ways;
    }
public:    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(s, 0, dp);
    }
};