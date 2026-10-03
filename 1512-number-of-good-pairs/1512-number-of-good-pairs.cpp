class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0 ;
        unordered_map<int,int> ans;
        for(int i = 0  ; i < nums.size() ; i++){
            int x = nums[i];
            
            if(ans.count(x)) count += ans[x];
            ans[x]++;
        }
        return count;
    }
};
