#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    stack<char> stk;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stk.push(s[i]);
        else {
            if(stk.empty()) return false;
            int c = stk.top();
            if(s[i] == ')') {
                if(c == '(') stk.pop();
                else return false;
            }
            else if(s[i] == '}') {
                if(c == '{') stk.pop();
                else return false;
            }
            else {
                if(c == '[') stk.pop();
                else return false;
            }
        }
    }
    return stk.empty();
}
int main() {
    return 0;
}