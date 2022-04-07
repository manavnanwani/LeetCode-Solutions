class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{')
                ss.push(s[i]);
            else{
                if(!ss.empty()){
                    if(s[i] == ')' && ss.top() != '(')
                        return false;
                    else if(s[i] == ']' && ss.top() != '[')
                        return false;
                    else if(s[i] == '}' && ss.top() != '{')
                        return false;
                    ss.pop();
                }
                else
                    return false;
                
            }
        }
        if(ss.empty())
            return true;
        return false;
    }
};