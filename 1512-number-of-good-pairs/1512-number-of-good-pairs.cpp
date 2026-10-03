class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        unordered_map<int,int> ans;
        for(int x : nums){            
            count += ans[x]++;
        }
        return count;
    }
};
