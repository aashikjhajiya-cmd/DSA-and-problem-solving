class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> topThree;
        for (int num : nums) {
            topThree.insert(num);
            if (topThree.size() > 3) {
                topThree.erase(topThree.begin());
            }
        }
        return topThree.size() == 3 ? *topThree.begin() : *topThree.rbegin();
    }
};
