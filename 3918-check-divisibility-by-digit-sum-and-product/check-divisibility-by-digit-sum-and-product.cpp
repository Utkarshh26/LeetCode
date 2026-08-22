class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0, prd =1,num = n;
        while(num > 0){
            int dig = num%10;
            sum += dig;
            prd *=dig;
            num /=10;
        }
        return n % (sum + prd) == 0;

    }
};