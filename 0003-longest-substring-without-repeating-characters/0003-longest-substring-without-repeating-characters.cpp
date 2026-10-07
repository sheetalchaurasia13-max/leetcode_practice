class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int>lastSeen(256, -1);        
        int maxLength = 0, left = 0;                
        for (int right=0; right < s.length(); ++right) {
            char currentChar = s[right];            
// If the character was seen inside the current window, move the left pointer
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }            
// Record/update the last seen index of the current character
            lastSeen[currentChar] = right;            
// Calculate the current window size and update max length
            maxLength = std::max(maxLength, right - left + 1);
        }        
        return maxLength;          
    }
};