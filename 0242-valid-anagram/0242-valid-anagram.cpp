class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int cnt[26] = {0};
        for(char c : s) cnt[c - 'a']++;
        for(char c : t) {
            if(--cnt[c-'a']<0) return false;
        }
        return true;
    }
};

// static const auto s = [](){
//   std::ios_base::sync_with_stdio(false);
//   std::cin.tie(NULL);
//   return 0;
// }();
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unordered_map<char , int> ans;
//         for(char x : s) ans[x]++;
//         if(s.size() != t.size()) return false;

//         for(char y : t){
//             if(!ans.count(y) || ans[y] <=0) return false;
//             ans[y]--;

//         }
//         return true;
//     }
// }; 