class Solution {
public:
    bool operand(string s) {
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string token : tokens) {
            if (operand(token)) {
                stk.push(stoi(token));
            } else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (token == "+") {
                    stk.push(a + b);
                } else if (token == "-") {
                    stk.push(a - b);
                } else if (token == "*") {
                    stk.push(a * b);
                } else {
                    stk.push(a / b);
                }
            }
        }
        return stk.top();
    }
};