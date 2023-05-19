class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<vector<int>>&result,vector<int>path,int src,int dest){
        path.push_back(src);
        if(src==dest){
             result.push_back(path);
            return;
}
            
            for(auto node:graph[src]){
                dfs(graph,result,path,node,dest);
            }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<vector<int>>paths;
        vector<int>path;
        if(nodes==0)
            return paths;
        dfs(graph,paths,path,0,nodes-1);
            return paths;
    }
};