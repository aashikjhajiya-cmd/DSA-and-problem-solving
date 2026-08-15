class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if (t == "+") st.push(op1 + op2);
                else if (t == "-") st.push(op1 - op2);
                else if (t == "*") st.push(op1 * op2);
                else st.push(op1 / op2);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
