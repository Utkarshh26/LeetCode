class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;

        vector<string> words;
        string word = "";
        
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        if (words.size() != pattern.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            if (mp1[pattern[i]] != mp2[words[i]]) return false;
            mp1[pattern[i]] = mp2[words[i]] = i + 1;
        }

        return true;
    }
};