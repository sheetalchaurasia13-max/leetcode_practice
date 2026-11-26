class Solution {
public:
    bool canAliceWin(int n) {
          
          for(int stone = 10 ; stone >=0 ; stone--){

            if(stone > n){
                return stone%2 == 1 ; // false 
            }
            else {
                n -= stone; 
            }
          }
          return false;
    }
};