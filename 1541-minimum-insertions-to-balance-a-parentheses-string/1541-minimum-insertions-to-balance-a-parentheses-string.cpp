class Solution {
public:
    int minInsertions(string s) {
        int open_needed = 0, closed_needed = 0;

        for (char x : s) {
            if (x == '(') {
                // If closed_needed is odd, we have a single ')' waiting.
                // We must complete it with an extra ')' (cost +1 open_needed)
                if (closed_needed % 2 != 0) {
                    open_needed++;
                    closed_needed--;
                }
                closed_needed += 2;
            } else {
                closed_needed--;
                // If we hit a excess ')', insert a '('
                if (closed_needed < 0) {
                    open_needed++;
                    closed_needed += 2;
                }
            }
        }

        return open_needed + closed_needed;
    }
};