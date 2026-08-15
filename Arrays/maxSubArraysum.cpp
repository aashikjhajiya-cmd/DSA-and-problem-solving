class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxn = INT_MIN;
    int currentsum = 0;

    for (int num : nums) {
        currentsum = max(num, currentsum + num);
        maxn = max(maxn, currentsum);
    }

    return maxn;
    }
};
