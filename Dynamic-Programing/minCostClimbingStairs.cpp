class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int option1 = dp[i - 1] + cost[i - 1];
            int option2 = dp[i - 2] + cost[i - 2];
            dp[i] = (option1 < option2) ? option1 : option2;
        }
        return dp[n];
    }
};
