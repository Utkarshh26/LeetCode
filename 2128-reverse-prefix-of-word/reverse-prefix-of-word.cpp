class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stk;
        bool found = false;
        int i = 0;
        for (i = 0; i < word.length(); i++) {
            stk.push(word[i]);

            if (word[i] == ch) {
                found = true;
                break;
            }
        }
        if (!found) {
            return word;
        }

        i = 0;
        while (!stk.empty()) {
            word[i] = stk.top();
            stk.pop();
            i++;
        }
        return word;
    }
};