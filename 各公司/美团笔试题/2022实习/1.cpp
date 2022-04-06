#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, r, b;
    cin>>n>>b>>r;
    string s;cin>>s;
    int needr = 0, needb = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) {
            if(s[i] == 'r') {
                needb++;
            } else {
                needr++;
            }
        }
    }
    if(needb <= b && needr <= r) {
        cout<<s.size() + needb + needr<<endl;
    } else {
        int resr = 0, resb = 0;
        if(needr > r) resr = needr - r;
        if(needb > b) resb = needb - b;
        cout<<resr<<endl;
        cout<<resb<<endl;
        // cout<<resr<<" "<<resb<<endl;
    }
    return 0;
}