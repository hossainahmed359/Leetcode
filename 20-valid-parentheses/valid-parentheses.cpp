class Solution {
public:
    char getOpeningParentheses(char c) {
        char openingParentheses;

        if (c == ')')
            openingParentheses = '(';
        else if (c == '}')
            openingParentheses = '{';
        else if (c == ']')
            openingParentheses = '[';

        return openingParentheses;
    }

    bool isValid(string s) {

        stack<char> st;
        bool flag = true;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty() || st.top() != getOpeningParentheses(ch)) {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }

        if(!st.empty()) {
            flag = false;
        }

        return flag;
    }
};