#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp; 
int main() {
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 1;
    mp['3'] = 2;
    mp['4'] = 1;
    mp['5'] = 2;
    mp['6'] = 2;
    mp['7'] = 3;
    mp['8'] = 1;
    mp['9'] = 2;
    mp['A'] = 2;
    mp['B'] = 3;
    mp['C'] = 2;
    mp['D'] = 3;
    mp['E'] = 3;
    mp['F'] = 4;
    string s;cin>>s;
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        res += mp[s[i]];
    }
    cout<<res<<endl;
    return 0;
}