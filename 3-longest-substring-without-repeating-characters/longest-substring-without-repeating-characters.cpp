class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int left = 0, right =0, maxlen =0, n =s.length();
        while(right < n){
            if(hash[s[right]] != -1){
                if(hash[s[right]] >= left){
                    left = hash[s[right]] + 1;
                }
            }
            hash[s[right]] = right;
            int len = right - left + 1;
            maxlen = max(maxlen, len);
            right++;
        }
        return maxlen;
    }
};