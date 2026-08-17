class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (size_t j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    int subProblem = dp[i - coins[j]];
                    if (subProblem != amount + 1 && subProblem + 1 < dp[i]) {
                        dp[i] = subProblem + 1;
                    }
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
