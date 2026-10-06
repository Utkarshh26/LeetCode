class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int count =0;;
        for(int i =0; i<s.length(); i++){
            if(s[i] == '('){
                stk.push(s[i]);
            }else if(s[i] =')'){
                if(!stk.empty() && stk.top() == '('){
                    stk.pop();
                }else{
                    count++;
                }
            }
        }
        while(!stk.empty()){
            count++;
            stk.pop();
        }
        return count;
    }
};