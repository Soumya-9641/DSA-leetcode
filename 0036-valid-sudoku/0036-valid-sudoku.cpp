class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        unordered_set<char>row[n];
        unordered_set<char>col[n];
        unordered_set<char>box[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.')
                    continue;
                char val=board[i][j];
                int boxpos= i/3*3+j/3;
                if(row[i].count(val)||col[j].count(val)||box[boxpos].count(val))
                    return false;
                 row[i].insert(val);
                col[j].insert(val);
                box[boxpos].insert(val);
            }
        }
        return true;
    }
};