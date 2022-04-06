#include<bits/stdc++.h>
using namespace std;
//shopee第一题
string s;
int n,k;
char getC(int index){
    for(int j = 0; j < k; j++) {
        char c = 'A' + j;
        if(index < n - 1 && s[index - 1] != c && s[index + 1] != c) {
            return c;
        }
        else if(index == n - 1 && s[index - 1] != c) {
            return c;
        }
    }
    return '&';
}
int main() {
    cin>>n>>k;
    cin>>s;
    if(k <= 2) {
        // 只有ABAB.... 或者 BABABA....
        int res1 = 0, res2 = 0;
        string temp = s;
        for(int i = 0; i < n; i++) {
            // ABABAB....
            if(i % 2 && s[i] != 'B') {
                res1++;
                s[i] = 'B';
            } else if(i % 2 == 0 && s[i] != 'A') {
                res1++;
                s[i] = 'A';
            }
            // BABABA....
            if(i % 2 && temp[i] != 'A') {
                res2++;
                temp[i] = 'A';
            } else if(i % 2 == 0 && temp[i] != 'B') {
                res2++;
                temp[i] = 'B';
            }
        }
        if(res1 <= res2) cout<<res1<<endl<<s<<endl;
        else cout<<res2<<endl<<temp<<endl;
    } else {
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                res++;
                s[i] = getC(i);
            }
        }
        cout<<res<<endl<<s<<endl;
    }
    return 0;
}