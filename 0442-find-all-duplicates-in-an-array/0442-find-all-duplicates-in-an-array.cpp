static const auto s = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0 ; 
}();
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>dup;
        vector<int>ans;
        for(auto x : nums){
            if(dup.count(x)) ans.push_back(x);
            dup.insert(x); 
        }
        return ans;
    }
};