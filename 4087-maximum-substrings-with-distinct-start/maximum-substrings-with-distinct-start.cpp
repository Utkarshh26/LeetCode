class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<int, int> mp;
        int count=0;
        for(int i=0; i< s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                count++;
            }
            mp.insert({s[i],0});
        }
        return count;
    }
};