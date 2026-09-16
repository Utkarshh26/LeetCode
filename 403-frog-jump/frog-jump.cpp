class Solution {
    unordered_map<int, int> st;
    vector<vector<int>> dp;

private:
    bool helper(vector<int>& stones, int idx, int jmp) {
        if (stones[idx] == stones.back()) {
            return true;
        }
        if (dp[idx][jmp] != -1) {
            return dp[idx][jmp];
        }
        if (jmp - 1 > 0) {
            int nextStone = stones[idx] + (jmp - 1);
            if (st.find(nextStone) != st.end()) {
                int nextIdx = st[nextStone];
                if (helper(stones, nextIdx, jmp - 1)) {
                    return dp[idx][jmp] = 1;
                }
            }
        }

        int nextStone =stones[idx] +jmp;
        if (st.find(nextStone)!= st.end()) {
            int nextIdx =st[nextStone];

            if (helper(stones,nextIdx, jmp)) {
                return dp[idx][jmp] = 1;
            }
        }
        nextStone = stones[idx] +(jmp + 1);
        if (st.find(nextStone)!= st.end()) {
            int nextIdx = st[nextStone];
            if (helper(stones, nextIdx,jmp + 1)) {
                return dp[idx][jmp] = 1;
            }
        }
        return dp[idx][jmp]= 0;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            st[stones[i]] = i;
        }
        if (stones[1] != 1) {
            return false;
        }
        dp.assign(n, vector<int>(n + 1, -1));
        return helper(stones, 1, 1);
    }
};