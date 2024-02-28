class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(char c : s){
            if(c=='c'){
                if(s1.size()<2)
                    return false;
                if(s1.top()!='b')
                    return false;
                else
                    s1.pop();
                if(s1.top()!='a')
                    return false;
                else
                    s1.pop();
            }
            else{
                s1.push(c);
            }
        }
        return s1.empty();
    }
};