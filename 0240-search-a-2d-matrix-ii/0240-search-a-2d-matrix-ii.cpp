class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         if(matrix[i][j]==target)
        //             return true;
        //     }
        // }
        // return false;
        int i=0,j=matrix[0].size()-1;
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size()){
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
};