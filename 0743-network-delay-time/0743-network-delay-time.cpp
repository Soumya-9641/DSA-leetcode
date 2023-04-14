class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int >dist(n+1,1e9);
        dist[k]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<times.size();j++){
                int u = times[j][0];
                int v = times[j][1];
                int wt = times[j][2];
                
                if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;
                 }
            }
        }
        
        //check for negative cycle
        int maxweight =0;
        for(int i=1;i<=n;i++){
            maxweight= max(maxweight,dist[i]);
            
        }
       return maxweight==1e9?-1:maxweight;
    }
};