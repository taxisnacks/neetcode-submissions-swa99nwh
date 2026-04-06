class Solution {
public:
    bool isValid(string s) {
        map<char, char> brackets = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack <char> seen;
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                seen.push(c);
            } 
            else {
                if (seen.empty() || seen.top() != brackets[c]){
                    return false;
                }
                seen.pop();
            }
        }
        return seen.empty();
    }
};
