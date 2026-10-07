// class Solution {
// public:
// int n;
// int maxLen ;
// unordered_set<string> st;

// void solve(string &s , int i , string &curr , int count){
//     if(count < 0) return ;
//     if(i == n){
//         if(count == 0){
//             if(curr.length() > maxLen){
//                 maxLen = curr.length(); 
//                 st.clear();
//             }
//             if(curr.length() == maxLen){
//                 st.insert(curr);
//             }
//         }
//         return ;
//     }

//     if(s[i] != ')' && s[i] != '('){ // alphabet
//         curr.push_back(s[i]);
//         solve(s , i+1 , curr , count);
//         curr.pop_back();
//         return ;
//     }

//     curr.push_back(s[i]);

//     solve(s, i+1, curr , count + (s[i] == '(' ? 1 : -1) );

//     curr.pop_back();

//     solve(s , i+1 ,curr ,count);
// }

//     vector<string> removeInvalidParentheses(string s) {
//         n = s.length();
//         st.clear();

//         maxLen = 0;

//         string curr = "";

//         solve(s, 0, curr , 0);

//         return vector<string>(begin(st) , end(st));
//     }
// };



class Solution {
    vector<string> ans;

    void dfs(string s, int start, int last, char open, char close){
        int balance = 0;

        for(int i = start; i<s.size(); i++){
            if(s[i] == open) balance++;
            if(s[i] == close) balance--;

            if(balance >= 0) continue;

            for(int j = last; j<=i; j++){
                if(s[j] == close && (j==last || s[j-1] != close)){
                    dfs(s.substr(0, j) + s.substr(j+1), i, j, open, close);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if(open=='('){
            dfs(s, 0, 0, ')', '(');
        }else{
            ans.push_back(s);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, 0, 0, '(', ')');
        return ans;
    }
};