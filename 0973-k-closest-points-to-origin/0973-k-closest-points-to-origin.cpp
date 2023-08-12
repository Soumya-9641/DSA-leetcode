class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        priority_queue<vector<int>>max_heap;
        for(auto& p:points){
            int x=p[0],y=p[1];
            max_heap.push({x*x+y*y,x,y});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        for(int i=0;i<k;i++){
            vector<int>top=max_heap.top();
            max_heap.pop();
            res[i]={top[1],top[2]};
        }
        return res;
    }
};