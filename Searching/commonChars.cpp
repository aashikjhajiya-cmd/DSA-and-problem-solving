
class Solution {
public:
    vector<string> commonChars(const vector<string>& words) {
        vector<int> min_freq(26, INT_MAX);
        
        for (const string& word : words) {
            vector<int> current_freq(26, 0);
            for (char ch : word) {
                current_freq[ch - 'a']++;
            }
            
            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], current_freq[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (min_freq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                min_freq[i]--;
            }
        }
        
        return result;
    }
};
