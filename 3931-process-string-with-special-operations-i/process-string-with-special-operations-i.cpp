class Solution {
public:
    string processStr(string s) {
        string result;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 97 && s[i] <= 122){
                result.push_back(s[i]);
            }else if(s[i] == '#'){
                result.append(result);
            }else if(s[i] == '%'){
                reverse(result.begin(), result.end());
            }else{
                if(!result.empty()){
                    result.pop_back();
                }
            }
        }
        return result;
    }
};