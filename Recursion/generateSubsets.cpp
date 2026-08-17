class Solution {
private:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        generateSubsets(index + 1, nums, current, result);
        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, result);
        current.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, nums, current, result);
        return result;
    }
};
