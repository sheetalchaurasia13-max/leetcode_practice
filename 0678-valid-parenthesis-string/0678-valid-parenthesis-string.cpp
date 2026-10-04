class Solution {
public:
    bool checkValidString(string s) {
       int nmin = 0 , nmax = 0;
       for(char c:s){
        nmin +=(c == '(')-(c==')')-(c=='*');
        nmax +=(c == '(')-(c==')')+(c=='*');
        if(nmax<0) return 0;
        nmin = max(0,nmin);
       } 
       return nmin == 0;
    }
};