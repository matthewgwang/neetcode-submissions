class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n%2 != 0) return false;

        stack<char> st;

        for (char c: s) {
            if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '(') {
                st.push(')');
            }

            else {
                if (st.empty() || st.top() != c) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
