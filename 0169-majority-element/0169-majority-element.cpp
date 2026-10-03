class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0 , count = 0 ;
        for(auto x : nums) {
            if(count == 0 ) can = x;
            count += (x != can? -1:1);
        }
        return can; 
    }
};