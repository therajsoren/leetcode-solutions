class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char it : s) {
            if (it == '(') {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            } else if (it == ')') {
                currentDepth--;
            }
        }
        return maxDepth;
    }
};