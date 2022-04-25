#include<bits/stdc++.h>
using namespace std;#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string Paired69(string S) {
        if(S.size() == 0) return "";
        int front6 = 0, last9 = 0;
        stack<char> stk;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '6') {
                stk.push(S[i]);
            } else {
                if(!stk.empty()) {
                    stk.pop();
                } else {
                    front6++;
                }
            }
        }
        last9 = stk.size();
        for(int i = 0; i < front6; i++) {
            S.insert(S.begin(), '6');
        }
        for(int i = 0; i < last9; i++) {
            S.push_back('9');
        }
        return S;
    }
};
int main() {
    return 0;
}