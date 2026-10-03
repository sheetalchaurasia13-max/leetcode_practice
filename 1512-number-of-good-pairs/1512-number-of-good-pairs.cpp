class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        unordered_map<int,int> ans;
        for(int x : nums){            
            if(ans.count(x)) count += ans[x];
            ans[x]++;
        }
        return count;
    }
};
