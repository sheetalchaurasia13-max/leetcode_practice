class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> a , b;
        for(auto i = 0 ; i<s.size() ; i++){
            int x = s[i] , y = t[i];
            if(a.count(x) && a[x] != y) return false;
            if(b.count(y) && b[y]  != x) return false ;
            a[x] = y;
            b[y] = x;            
        }
        return true ;
    }
};

// note that one to one and onto if combine together they called bijetive --> the one to one and onto is --> if eachand every domain has unique and one element assigned in codomain . then it wwill called the one to  one  and if vise versa true then it is called the bijective . 



//  here we need to fulfill the bijective conditions