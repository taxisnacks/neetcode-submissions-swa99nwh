class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pMap{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> pStack;

        for (char ch : s){
            if(ch == '[' || ch == '(' || ch == '{'){
                pStack.push(ch);
            }
            else{
                if (pStack.empty()) return false;
                if (pStack.top() != pMap[ch]) return false;
                pStack.pop();
            }
        }
        return pStack.empty();
    }
};
