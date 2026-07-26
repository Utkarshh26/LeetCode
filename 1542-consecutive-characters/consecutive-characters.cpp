class Solution {
public:
    int maxPower(string s) {
        stack<char> st;
        int maxpower = INT_MIN, power =1;
        for(char ch: s){
            if(!st.empty() && ch == st.top()){
                power++;
            }else{
                maxpower = max(maxpower,power);
                power= 1;
            }
            st.push(ch);
        }
        maxpower= max(maxpower, power);
        return maxpower;
    }
};