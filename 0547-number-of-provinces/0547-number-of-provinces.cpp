class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited, int n) {  // fix 2: vector<bool>&
        
        visited[node] = true;
        
        for(int j = 0; j < n; j++) {
            if(isConnected[node][j] == 1 && !visited[j] && node != j) {
                dfs(j, isConnected, visited, n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int province = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited, n);  // fix 1: visited
                province++;
            }
        }

        return province;
    }
};