class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>q;
        string ans="";
        for(char c:s){
            if( c =='('){
                if(!q.empty()){
                    ans+=c;
                }
                q.push(c);
            }

            else{
                q.pop();
                if(!q.empty()){
                    ans+=c;
                }
            }
        }
      
        return ans;
    }
};