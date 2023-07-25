class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                int first=st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int add =first+second;
                st.push(add);
                
            }
            else if(tokens[i]=="-"){
               int first=st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int sub= second-first;
                st.push(sub);
                
            }
            else if(tokens[i]=="/"){
                int first=st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int div= second/first;
                st.push(div);
                
            }
            else if(tokens[i]=="*"){
                int first=st.top();
                st.pop();
                int second= st.top();
                st.pop();
                int mul = first*second;
                st.push(mul);
                
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};