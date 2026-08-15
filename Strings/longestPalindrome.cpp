class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool has_odd = false;
        
        for (auto& pair : count) {
            length += (pair.second / 2) * 2;
            if (pair.second % 2 == 1) {
                has_odd = true;
            }
        }
        
        if (has_odd) {
            length += 1;
        }
        return length;
    }
};
