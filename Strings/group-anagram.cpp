class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<string>> anagram;
        for (const string& s : strs) {
            string sorted_key = s;
            sort(sorted_key.begin(), sorted_key.end());
            anagram[sorted_key].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(anagram.size()); 
        
        for (auto& pair : anagram) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
