class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1;

        if (n == 0) return 1;
        if (n == 1) return 10;
        int comb = 9;

        for(int i = 0; i < n; i++){
            count *= comb;
            if (i != 0) comb--;
        }
        
        return count  + countNumbersWithUniqueDigits(n-1);
    }
};