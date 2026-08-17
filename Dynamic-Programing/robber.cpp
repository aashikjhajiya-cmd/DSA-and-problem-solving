class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
        for (int i = 2; i < n; i++) {
            int take = nums[i] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = (take > skip) ? take : skip;
        }
        return dp[n - 1];
    }
};
