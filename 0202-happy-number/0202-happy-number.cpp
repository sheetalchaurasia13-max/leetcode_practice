class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>ans;
       while( n != 1 && !ans.count(n) ){
        ans.insert(n);
        int s = 0;
        for( ; n>0 ; n/=10){
            s += (n%10)*(n%10);
        }
        n = s;
       } 
       return n==1;
    }
};


// brute force;

// static const auto s = [](){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     return 0;
// }();
// class Solution {
// public:
//    int sqDigits(int n){
//     int sum = 0 ;
//     while(n){
//         sum += (n%10)*(n%10);
//         n = n/10;
//     }
//     return sum;
//    }
//     bool isHappy(int n) {
//         unordered_set<int>ans;
//         while(n != 1){
//             if(ans.count(n)) return false;
//             ans.insert(n);
//             n = sqDigits(n);
//         }
//         return true;
//     }
// };