class Solution {
public:
    bool backspaceCompare(string s, string t) {

     stack<char>s1,t1;
        // for s
        for(const auto c : s){
            if(s1.size() > 0  && c == '#') s1.pop();
            else if(c != '#')s1.push(c);
        } 
        // for t
        for(const auto c : t){
            if(t1.size() > 0  && c == '#') t1.pop();
            else if(c != '#')t1.push(c);
        } 
        
        // compare 
        if(s1.size() != t1.size()) return false;
        else if(s1.empty() && t1.empty()) return  true;
        else{
            while(!s1.empty()){
                if(s1.top() != t1.top()) return false;
                else{
                    s1.pop();
                  t1.pop();
                }
            }
            return true;
        }        
    }
};