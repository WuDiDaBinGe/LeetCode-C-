#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n = s.size();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    stack<char> stk;
    stk.push('y');stk.push('s');stk.push('a');stk.push('e');
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == stk.top()) {
            stk.pop();
            if(stk.empty()) {
                res++;
                stk.push('y');stk.push('s');stk.push('a');stk.push('e');
            }
        }
    }
    cout<<res<<endl;
    return 0;
}