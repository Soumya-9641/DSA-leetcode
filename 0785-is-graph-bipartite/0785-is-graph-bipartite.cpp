class Solution {
public:
    
    vector<int>vis,color;
    bool dfs(int node,int col,vector<vector<int>>& graph){
        vis[node]=1;
        color[node]=col;
        for(int child :graph[node]){
            if(vis[child]==0){
                 if(dfs(child,col^1,graph)==false) 
                    return false;
            }
             else{
                if(color[node]==color[child])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vis.resize(n);
        color.resize(n);
       
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                if(dfs(i,0,graph)==false)
                    return false;
            }
        }
        return true;
    }
};