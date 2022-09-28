#include<bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> stk;    
    int cur = 0;
    for(int i = 0; i < n; i++) {
        stk.push(pushed[i]);
        while(!stk.empty() && cur < n && stk.top() == popped[cur]) {
            cur++;
            stk.pop();
        }
    }    
    return stk.empty();
}
int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {4,3,5,1,2};
    cout<<validateStackSequences(a, b);
    return 0;
}