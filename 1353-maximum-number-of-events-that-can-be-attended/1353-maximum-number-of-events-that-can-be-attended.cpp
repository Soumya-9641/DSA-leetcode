class Solution {
public:
   
    
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
       sort(events.begin(),events.end());
        int i=0,res=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int d =1;d<1000001;++d){
            while(pq.size() && pq.top()<d)
                pq.pop();
            while(i<n && events[i][0]==d)
                pq.push(events[i++][1]);
            if(pq.size()){
                pq.pop();
                ++res;
            }
        }
        return res;
    }
};