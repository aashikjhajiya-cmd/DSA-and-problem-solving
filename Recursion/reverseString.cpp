
class Solution {
private:
    void helper(std::vector<char>& s, int left, int right) {
        if (left >= right) return;
        std::swap(s[left], s[right]);
        helper(s, left + 1, right - 1);
    }
public:
    void reverseString(std::vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};
