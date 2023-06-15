class Solution {
private:
    vector<int>nextSmall(vector<int>& heights,int n){
         stack<int>st;
    vector<int>ans(n);
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);

    }
    return ans;
    }
    
     vector<int>prevSmall(vector<int>& heights,int n){
         stack<int>st;
    vector<int>ans(n);
    st.push(-1);
    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);

    }
    return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = nextSmall(heights,n);
        vector<int>prev(n);
        prev= prevSmall(heights,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l= heights[i];
         
            if(next[i]==-1){
                next[i]=n;
            }
               int b= next[i]-prev[i]-1;
            int newarea = l*b;
            area = max(area,newarea);
        }
        return area;
    }
};