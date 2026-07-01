class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch != ']'){
                st.push(ch);
            }else{
                string str = "";
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                int times = stoi(num);
                string reps = "";
                for(int i = 0; i< times; i++){
                    reps += str;
                }
                for(char c : reps){
                    st.push(c);
                }
            }
        }
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};