class Solution {
public:
    bool isValid(string s) {
        unordered_map<char ,char> mt = {{')' , '('} ,{']' , '['} ,{'}' , '{'}  };
        stack<char>st;
        for(auto c : s){
            // condition for pop
            if(mt.count(c)){
                if(st.empty() || st.top() != mt[c]) return false; 
                else st.pop();                
            }
            else st.push(c);            
        }
       if(st.empty()) return true;
       else return false;
    }
};