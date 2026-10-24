class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int fst = INT_MAX;
        int sec = INT_MAX;
        
        for (int n : nums) {
            if (n<= fst)  fst = n;                
            else if (n<= sec)  sec = n;                
            else return true;    
         }        
        return false;
    }
};