class Solution {
public:
    int myAtoi(string s) {
        int n =s.length(), i=0,sign=1;
        while(i <n && s[i]==' '){
            i++;
        }

        if(i <n &&(s[i] =='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign= -1;
            }
            i++;
        }

        long long int ans =0;
        while(i<n && isdigit(s[i])){
            int dig = s[i] -'0';
            if(ans > (INT_MAX - dig)/10){
                return sign == 1? INT_MAX :INT_MIN;
            }
            ans = ans * 10+dig;
            i++;
        }
        return sign*ans;
    }
};