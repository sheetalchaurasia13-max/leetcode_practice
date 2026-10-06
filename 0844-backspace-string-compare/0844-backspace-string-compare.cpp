class Solution {
public:
stack<char> Check(const string &s){
    stack<char>s1;
        // for s
        for(const auto c : s){
            if(s1.size() > 0  && c == '#') s1.pop();
            else if(c != '#')s1.push(c);
        } 
        return s1;
}

    bool backspaceCompare(string s, string t) {

      return Check(s)==Check(t);       
    }
};