class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idx = 0,ans=0;
        for(int i =0; i<s.size();i++){
            if(idx <g.size() &&g[idx] <= s[i]){
                ans++;
                idx++;
            }
        }
        return ans;
    }
};