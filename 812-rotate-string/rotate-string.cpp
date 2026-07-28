class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        for(int i = 0; i< len; i++){
            char ch = s[0];
            for(int i = 1; i < len; i++){
                s[i-1] =s[i];
            }
            s[len -1] =ch;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};