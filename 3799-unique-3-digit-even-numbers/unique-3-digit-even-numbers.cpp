class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;
        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0) {
                continue;
            }
            
            int a = num / 100, b = (num / 10) % 10, c = num % 10;
            if (a == b && b == c) {
                if (freq[a] >= 3) {
                    ans++;
                }
            }
            else if (a == b) {
                if (freq[a] >= 2 && freq[c] >= 1) {
                    ans++;
                }
            }
            else if (a == c) {
                if (freq[a] >= 2 && freq[b] >= 1) {
                    ans++;
                }
            }
            else if (b == c) {
                if (freq[b] >= 2 && freq[a] >= 1) {
                    ans++;
                }
            }
            else {
                if (freq[a] >= 1 &&freq[b] >= 1 &&freq[c] >= 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};