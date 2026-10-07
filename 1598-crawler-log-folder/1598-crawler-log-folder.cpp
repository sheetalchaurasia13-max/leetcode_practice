class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0 ; 
        for(auto c : logs){
            if(c == "../") {
                if(depth > 0) depth--;
            }
            else if(c == "./"){
                continue;
            }
            else depth++;
        }
        return depth;
    }
};