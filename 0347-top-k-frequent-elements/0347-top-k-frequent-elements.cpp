class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(const auto & i : nums) mp[i]++;

        vector<pair<int,int>> store(mp.begin(),mp.end());
        sort(store.begin(),store.end() , [](const auto &p1 , const auto &p2){
            return p1.second>p2.second;
        });

        vector<int>ans;
        for(int i =0 ; i<k ; i++){
            ans.push_back(store[i].first);
        }
        return ans;
    }
};