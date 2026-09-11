class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();

        int profit = 0;

        for (int i = 0; i<length-1; i++) {
            for (int j= i+1; j<length; j++) {
                int transaction = prices[j] - prices[i];

                if (transaction > profit) {
                     profit = transaction;
                }
            }
        }
        return profit;
    }
};
