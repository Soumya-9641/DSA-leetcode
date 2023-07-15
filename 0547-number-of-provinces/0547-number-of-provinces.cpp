class Solution {
public:
    
    void dfs(int node,vector<int>adjList[],vector<int>&vis ){
        vis[node]=1;
        for(auto it: adjList[node]){
            if(!vis[it])
                dfs(it,adjList,vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m = isConnected[0].size();
        vector<int>adjList[n];
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjList,vis);
            }
        }
        return cnt;
        
    }
};