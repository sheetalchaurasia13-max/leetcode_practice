class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         map <string , int>mp;
         for(auto x : words){
            mp[x]++;
         }
        //  sorting by value 
        // take into vector of pairs
        vector< pair<string , int> > vec(mp.begin() , mp.end());
        sort(vec.begin() ,vec.end() , [](auto &p1 , auto &p2){
            if(p1.second==p2.second) return p1.first < p2.first; // lexicographically smaller word first 
            return p1.second > p2.second;
        });

        // extract the value;
        vector<string>result;
        for(int i = 0 ; i<k ; i++){
            result.push_back(vec[i].first);
        }
        return result;    

    }
};