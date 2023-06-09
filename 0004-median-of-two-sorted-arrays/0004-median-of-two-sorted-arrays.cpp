class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
//         int m = nums1.size();
//         int n = nums2.size();
//         int ans[m+n];
//         int i=0,j=0,k=0;
//         while(i<m && j<n){
//             if(nums1[i]<nums2[j]){
//                 ans[k++]=nums1[i++];
//             }
//              if(nums1[i]>nums2[j]){
//                 ans[k++]=nums2[j++];
//             }
//         }
//         if(i<m){
//             while(i<m){
//                 ans[k++]=nums1[i++];
//             }
//         }
//         if(j<n){
//             while(j<n){
//                 ans[k++]=nums2[j++];
//             }
//         }
        
//         n= n+m;
//         if(n%2==1){
//             return ans[((n+1)/2)-1];
            
//         }else{
//             return ((float)ans[(n/2)-1]+(float)ans[(n/2)])/2;
//         }
        
        //optimize
        vector<int>v;
        for(auto num:nums1){
            v.push_back(num);
        }
        for(auto num:nums2){
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        int n= v.size();
        if(n%2==1){
            return v[(n)/2];
        }else{
            return ((float)v[(n/2)-1]+(float)v[n/2])/2;
        }
    }
};