class Solution {
public:
    int maxPower(string s) {
        int maxpower = 1, power = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                power++;
            } else {
                maxpower = max(maxpower, power);
                power = 1;
            }
        }
        return max(maxpower, power);
    }
};