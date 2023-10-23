class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> umap;
    for(auto x: nums)
    {
      umap[x]++;
    }
    priority_queue<pair<int,int>, vector< pair<int,int> >, greater<pair<int,int> >> pq;
    // PUSH ELE INTO MIN HEAP 
    for(auto x: umap)
    {
      pq.push(make_pair(x.second,x.first));
      // IF MIN HEAP SIZE IS GRETAER THAN K THEN POP , IT WILL POP THE SMALLEST FREQUENCY ELEMENT 
      if(pq.size()>k)
      {
        pq.pop();
      }
    }
    vector<int>ans;
    while(!pq.empty())
    {
      pair<int,int>temp=pq.top();
      pq.pop();
      ans.push_back(temp.second);
    }
    return ans;
    }
};