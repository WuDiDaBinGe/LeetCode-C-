#include<bits/stdc++.h>
using namespace std;
int isDiv3(string num) {
    int sum = 0;
    for(int i = 0; i < num.size(); ++i) {
        sum += (num[i] - '0');
    }
    return sum;
}
int main(){
    int T;cin>>T;
    while(T--) {
        string s;cin>>s;
        int sum = isDiv3(s);
        int count = 0, index = -1;
        int mod = sum % 3;
        for(int i = 0; i < s.size(); ++i) {
            int num = s[i] - '0';
            if(num % 3 == mod) {
                count++;
                index = i;
                break;
            }
        }
        if(count == 0 ) {
            cout<<0<<endl;
        } else {
            for(int i = 0; i < s.size(); ++i) {
                if(i == index) continue;
                int num = s[i] - '0';
                if(num % 3 == 0) count++;
            }
            if(count == s.size()) cout<<count - 1<<endl;
            else cout<<count<<endl;
        }
    }
    return 0;
}