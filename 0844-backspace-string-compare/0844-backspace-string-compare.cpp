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
        
      return s1==t1;       
    }
};