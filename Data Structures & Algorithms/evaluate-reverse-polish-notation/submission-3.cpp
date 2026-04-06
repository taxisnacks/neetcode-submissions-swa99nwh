class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string op;
        int operand1;
        int operand2;
        stack<string> s;

        cout << "starting loop" << endl;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                cout << "operator found: " << tokens[i] << endl;
                op = tokens[i];
                operand1 = stoi(s.top());
                s.pop();
                operand2 = stoi(s.top());
                s.pop();
                if (op == "+"){
                    cout << "adding " << operand1 << " and " << operand2 << endl;
                    s.push(to_string(operand2 + operand1));
                } else if (op == "-"){
                    cout << "subtracting " << operand2 << " and " << operand1 << endl;
                    s.push(to_string(operand2 - operand1));
                } else if (op == "/"){
                    cout << "dividing " << operand1 << " and " << operand2 << endl;
                    s.push(to_string(operand2 / operand1));
                } else if (op == "*"){
                    cout << "multiplying " << operand1 << " and " << operand2 << endl;
                    s.push(to_string(operand2 * operand1));
                }
            }  else {
                    cout << "number found: " << tokens[i] << endl;
                    s.push(tokens[i]);
            }
            cout << "new top of stack: " << s.top() << endl;
        }
        return stoi(s.top());
    }
};
