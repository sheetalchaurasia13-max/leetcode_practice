class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size(); //5 

        for(auto x : nums){
            int indx = abs(x)-1 ; // index  == element-1 ; (here only )

            if(nums[indx] < 0){
                return abs(x) ;
            }
            else{
                nums[indx] = -1*nums[indx];
            }
       }
       return 0;
    } 

};