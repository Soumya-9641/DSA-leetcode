class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        char x;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push(s[i]);
                continue;
            }
            if(stack.empty()){
                return false;
            }
            switch(s[i]){
                case ')':
                     x = stack.top();
                     stack.pop();
                    if(x=='{' || x=='[')
                        return false;
                    break;
                    
                case '}':
                     x = stack.top();
                     stack.pop();
                    if(x=='(' || x=='[')
                        return false;
                    break;
                    
                case ']':
                     x = stack.top();
                     stack.pop();
                    if(x=='{' || x=='(')
                        return false;
                    break;
                    
            }
        }
         return stack.empty();
    }
   
};