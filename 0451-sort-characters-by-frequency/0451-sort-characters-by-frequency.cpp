class Solution {
public:
    string frequencySort(string s) {
        map<char, int>mp;
        for(const auto &ch : s) mp[ch]++;

        vector<pair<char,int>>store(mp.begin() ,mp.end());
        sort(store.begin(),store.end() , [](const auto &p1 ,const auto &p2){
            return p1.second>p2.second;
        });

        string result ;
        for( auto p : store){
            while(p.second){
                 result.push_back(p.first);
                 p.second--;
            }  
        } 
        return result;
    }
};