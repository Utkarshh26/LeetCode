class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(128, -1); 
        vector<int> m2(128, -1); 

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (m1[c1] != -1 && m1[c1] != c2) return false;
            if (m2[c2] != -1 && m2[c2] != c1) return false;

            m1[c1] = c2;
            m2[c2] = c1;
        }

        return true;
    }
};