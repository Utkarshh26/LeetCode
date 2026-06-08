class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        vector<int> dp(n + 1);
        dp[1] = 9;
        int available = 9;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * available;
            available--;
        }

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans += dp[i];
        }

        return ans;
    }
};