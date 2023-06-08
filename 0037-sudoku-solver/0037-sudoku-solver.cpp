class Solution {
public:
    
    
    bool isSafe(vector<vector<char>>& board,int row,int col,char val){
        int n= board[0].size();
        for(int i=0;i<n;i++){
            //row
            if(board[row][i]==val){
                return false;
            }
            if(board[i][col]==val){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        int n= board[0].size();
        for(int row =0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    for(char val='1';val<='9';val++){
                        if(isSafe(board,row,col,val)){
                            board[row][col]=val;
                            bool nextSol= solve(board);
                            if(nextSol)
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};