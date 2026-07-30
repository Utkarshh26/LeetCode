class Solution {
public:
    vector<bool> vis;

    void dfs(int vertex, vector<vector<int>>& isConnected) {
        vis[vertex] = true;
        for (int child = 0; child < isConnected.size(); child++) {
            if (isConnected[vertex][child] == 1 && !vis[child]) {
                dfs(child, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vis.resize(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected);
            }
        }
        return provinces;
    }
};