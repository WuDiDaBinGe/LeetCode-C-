#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
    stack<int> nums;
    stack<char> operates;
    int n = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            n = n * 10 + (s[i] - '0');
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || i == s.size() - 1) {
            if(operates.empty()) {
                nums.push(n);
            }
            else if(!operates.empty() && operates.top() == '+') {
                nums.push(n);
            }
            else if(!operates.empty() && operates.top() == '-') {
                nums.push(-n);
            }
            else if(!operates.empty() && operates.top() == '/') {
                int x = nums.top() / n;
                operates.pop();
                nums.pop();
                nums.push(x);
            }
            else if(!operates.empty() && operates.top() == '*') {
                int x = nums.top() * n;
                operates.pop();
                nums.pop();
                nums.push(x);
            }
            n = 0;
            if(i < s.size() - 1) operates.push(s[i]);
        }
    }
    int res = 0;
    while(!nums.empty()) {
        int a = nums.top(); nums.pop();
        res += a;
    }
    return res;
}
int main() {
    cout<<calculate(" 3+5 / 2 ")<<endl;
    return 0;
}