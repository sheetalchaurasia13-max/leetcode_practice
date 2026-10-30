class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
            
        string s = "0123456789abcdef", ans = "";
        unsigned int n = num; // Handle negative numbers using two's complement via unsigned casting
        
        while (n > 0) {
            ans += s[n & 15];
            n >>= 4;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};