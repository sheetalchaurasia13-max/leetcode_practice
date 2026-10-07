class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0 ;
        for(auto x : nums) {
            total += x; // total sum
        }

         int lsum = 0 , rsum = 0;
         for(int i = 0 ; i< nums.size() ; i++){
            if( i == 0 ) lsum = 0;  // add left side code  ';
            else lsum += nums[i-1];  // add left side code  ';
            
            rsum = (total-nums[i]-lsum); // sum all right sum ;
            if(lsum == rsum){
               return i;   break;
            }      
         } 
         return -1;
    }
};