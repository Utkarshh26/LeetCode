class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minPrice) {
                profit = max(profit, prices[i] - minPrice);
            }
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};