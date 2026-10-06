class Solution {
public:
    int minAddToMakeValid(string s) {
        int closed_needed = 0, open_needed = 0 ;
        for(char x : s){
            if(x == '(') closed_needed++;
            else{
                if(closed_needed > 0) closed_needed--;
                else open_needed++;
            }
        }
        return open_needed + closed_needed;
    }
};
/*class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0 ;
        stack<char>st;
       
        for(char c : s){
            if(c == '(') {
                st.push('('); count++;
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop(); count--;
                }
                else {
                    st.push(')');
                    count++;
                }
            }
            
        }
       
        return count;
    }
};*/