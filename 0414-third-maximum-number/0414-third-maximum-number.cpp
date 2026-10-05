class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        
        // If there are less than 3 distinct elements, return the max (largest element)
        if (s.size() < 3) {
            return *s.rbegin(); 
        }
        
        // Otherwise, return the 3rd maximum element from the end
        return *next(s.rbegin(), 2);
    }
};