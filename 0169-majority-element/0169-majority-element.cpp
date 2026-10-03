class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0 , count = 0 ;
        for(auto x : nums) {
            if(count == 0 ) can = x;
            if(x != can) count--;
            else count++;
        }
        return can; 
    }
};