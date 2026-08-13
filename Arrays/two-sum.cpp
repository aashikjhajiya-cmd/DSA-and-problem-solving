class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen;
        
        seen.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];
            
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            
            seen.emplace(nums[i], i);
        }
        
        return {};
        
    }
};
