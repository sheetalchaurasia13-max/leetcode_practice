class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin()  , nums.end());

        int m = nums[n/2];
        int s = 0 ; 
        for(int num : nums){
            s += abs(num - m);
        }
        return s;

    }
};