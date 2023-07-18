class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
            dis[0][0]=0;
        queue<pair<int,pair<int,int>>>q;
        if(n==1 && grid[0][0]==0)
            return 1;
        
        if(grid[0][0]==1)
            return -1;
        q.push({0,{0,0}});
        int dr[] ={-1,0,0,+1,-1,+1,-1,+1};
        int dc[]={0,+1,-1,0,-1,+1,+1,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int r=it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<8;i++){
                int newr= r+dr[i];
                int newc= c+ dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==0 && dist+1<dis[newr][newc]){
                    dis[newr][newc]=1+dist;
                    if(newr==n-1 && newc==m-1)
                        return dist+2;
                    q.push({1+dist,{newr,newc}});
                }
            }
        }
        return -1;
    }
};