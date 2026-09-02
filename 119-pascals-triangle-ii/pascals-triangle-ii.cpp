class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        int n = rowIndex +1;
        for (int i = 0; i < n; i++) {
            vector<int> v(i + 1, 1);
            if (i >= 2) {
                for (int j = 1; j < i; j++) {
                    v[j] = ans[i-1][j] + ans[i-1][j-1];
                }
            }
            ans.push_back(v);
        }
        return ans[rowIndex];
    }
};