#include<bits/stdc++.h>
using namespace std;
#define Yu 1000000007
unordered_map<char, int> hasht;
unordered_set<long long> sets;
int main() {
    string s; cin>>s;
    int n = s.size();
    hasht['A'] = 10;
    hasht['B'] = 11;
    hasht['C'] = 12;
    hasht['D'] = 13;
    hasht['E'] = 14;
    hasht['F'] = 15;
    vector<long long> resv;
    char a = '0', b = 'A' - 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            if(s[i] > a) a = s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            if(s[i] > b) b = s[i];
        }
    }
    int jinzhi = 2;
    if(b != 'A' - 1){
        jinzhi = hasht[b] + 1;
    } else {
        jinzhi = a - '0' + 1;
    }
    for(int i = jinzhi; i <= 16; ++i) {
        long long res = 0;
        long long ch = 1;
        if(i <= 10 ){
            for(int j = n - 1; j >= 0; j--) {
                res += (ch * (s[j] - '0'));
                ch = ch * i;
            } 
            if(sets.count(res % Yu) == 0) {
                sets.insert(res % Yu);
                resv.push_back(res % Yu);
            }
        } else if(i > 10 ) {
            for(int j = n - 1; j >= 0; j--) {
                if(s[j] >= 'A' && s[j] <= 'F') {
                    res += (ch* hasht[s[j]]);
                } else {
                    res += (ch * (s[j] - '0'));
                } 
                
                ch = ch * i;
            }
            // cout<<i<<endl;
            if(sets.count(res % Yu) == 0) {
                sets.insert(res % Yu);
                resv.push_back(res % Yu);
            }
            
        }
    }
    sort(resv.begin(), resv.end());
    for(int i = 0; i < resv.size(); i++) {
        cout<<resv[i]<<endl;
    }
    return 0;
}