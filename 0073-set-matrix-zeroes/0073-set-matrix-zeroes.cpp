class Solution {
public:
    
      void makeRow(vector<vector<int>>& matrix,int i,int n){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-99999999;
            }
        }
    }
     void makeCol(vector<vector<int>>& matrix,int j,int m){
        for(int i=0;i<m;i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-99999999;
            }
        }
    }
   
    
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
    int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    makeRow(matrix,i,n);
                    makeCol(matrix,j,m);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-99999999){
                    matrix[i][j]=0;
                }
            }
        }
    }
};