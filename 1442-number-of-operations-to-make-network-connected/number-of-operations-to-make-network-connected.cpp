class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        vis[start]=1;
        for(int neg :adj[start]){
            if(!vis[neg]){
                dfs(neg,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }
        vector<vector<int>> adj(n);

        for(auto & con :connections){
        int u=con[0];
        int v=con[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    int com=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            com++;
            dfs(i, adj, vis);
                   }
    }
    return com-1;
    }
};