class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int b = 0 ;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '(') {                
                if(b > 0) ans += s[i];
                b++;
            }
            else if(s[i] == ')'){    
                b--;            
                if(b > 0) ans += s[i];               
            }
        }
        return ans;
    }
};