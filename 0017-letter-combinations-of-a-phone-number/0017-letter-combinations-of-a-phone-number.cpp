class Solution {
public:
    
    void backtrack(string &digits,vector<string>&pad,vector<string>&output,string temp,int index){
        //base case
        if(index>=digits.size()){
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0;i<value.size();i++){
            temp.push_back(value[i]);
            backtrack(digits,pad,output,temp,index+1);
            temp.pop_back();
        }
        
        
    }
    
    vector<string> letterCombinations(string digits) {
            if(digits.empty())
                return {};
        vector<string>pad={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>output;
        string temp;
        backtrack(digits,pad,output,temp,0);
        return output;
    }
};