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
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            int num = s[i] - '0';
            if((sum - num) % 3 == 0) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}