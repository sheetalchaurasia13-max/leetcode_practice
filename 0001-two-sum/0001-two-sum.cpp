// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//            int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {}; 
//     }
// };


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> seen;
//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];
//             if (seen.count(complement))
//                 return {seen[complement], i};
//             seen[nums[i]] = i;
//         }
//         return {};
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(auto c = 0 ; c< nums.size() ; c++){
            auto it = seen.find(target-nums[c]);
            if(it != seen.end()) return {it->second, c};
            seen[nums[c]] = c;
        }
        return {};
    }
        
    
};