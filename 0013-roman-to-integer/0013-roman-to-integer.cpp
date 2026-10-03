// static const auto s = [](){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     return 0;
// }();
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char , int> store = {{'I' , 1} ,{'V' , 5},{'X' , 10},{'L' , 50},{'C' , 100},{'D' , 500},{'M' , 1000} };

     
        int total = 0;
        for(int i = 0 ; i< s.size() ; i++){
            if(store[s[i]] < store[s[i+1]] ) total -= store[s[i]];
            else total += store[s[i]];
        }
        return total ;
    }
};