class Solution {
public:
   int sqDigits(int n){
    int sum = 0 ;
    while(n){
        sum += (n%10)*(n%10);
        n = n/10;
    }
    return sum;
   }
    bool isHappy(int n) {
        unordered_set<int>ans;
        while(n != 1){
            if(ans.count(n)) return false;
            ans.insert(n);
            n = sqDigits(n);
        }
        return true;
    }
};