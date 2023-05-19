class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>graph;
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
     vector<bool>visited(n,0);
        queue<int>q;
        visited[source]=1;
        q.push(source);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur==destination)
                return true;
            
            for(auto &node:graph[cur]){
                if(!visited[node]){
                    visited[node]=1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};