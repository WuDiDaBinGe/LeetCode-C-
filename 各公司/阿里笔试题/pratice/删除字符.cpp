#include<bits/stdc++.h>
using namespace std;
// 单调栈
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n, d; cin>>n>>d;
        int length = n - d;
        stack<char> stk;
        string s; cin>>s;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i];
            while(d > 0 && !stk.empty() && c < stk.top()) {
                stk.pop();
                d--;
            }
            stk.push(c);
        }
        string res = "";
        while (!stk.empty()) {
            res.insert(res.begin(), stk.top());
            stk.pop();   
        }
        cout<<res.substr(0, length)<<endl;
    }
}