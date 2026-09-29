class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch =='(' || (ch >= 'a'&& ch <='z' )){
                st.push(ch);
            }else{
                string str ="";
                while(st.top() != '('){
                    str = str+ st.top();
                    st.pop();
                }
                st.pop();
                for(int i =0; i< str.length(); i++){
                    st.push(str[i]);
                }
            }
        }
        string ans= "";
        while(!st.empty()){
            ans =st.top()+ans;
            st.pop();
        }
        return ans;
    }
};