class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];

            if (stack.empty()) {
                stack.push(a);
                continue;
            }

            if (a == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (a == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(a);
            }
        }

        return stack.size();
    }
};