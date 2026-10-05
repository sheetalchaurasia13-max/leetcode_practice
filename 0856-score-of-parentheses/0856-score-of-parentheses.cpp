class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0 , ans = 0;
        for(int i = 0 ; i<s.size(); i++){
            if(s[i] == '(') depth++;
            else{
                depth--;
                if(s[i-1] == '(')
                ans += 1<<(depth); // d = 1 == 

            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(auto c : s){
            if(c== '(') st.push(0);
            else{
              int v = st.top() ; st.pop();     
               if(v==0) st.top()++;
                else st.top() += 2*v;           
            }           
        }
        return st.top();
    }
};*/