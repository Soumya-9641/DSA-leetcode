class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>a(2002,0);
        for(int i=0;i<arr.size();i++){
            a[arr[i]+1000]++;
        }
        sort(a.begin(),a.end());
        for(int i=a.size()-1;i>0;i--){
            if(a[i]==a[i-1] && (a[i]!=0||a[i-1]!=0))return false;
        }
        return true;
    }
};