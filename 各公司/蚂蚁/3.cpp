#include<bits/stdc++.h>
using namespace std;
int solve(string& s) {
    unordered_map<char, int> mp;
    int l = 0, n = s.size();
    int r = 0;
    int res = INT_MIN;
    if(n == 0 || n == 1) return n;
    while(r < n){
        char c = s[r];
        mp[c]++;
        r++;
        while(mp[c] > 1){
            char c2 = s[l];
            mp[c2]--;
            l++;
        }
        res = max(res, r- l);
    }
    return res;
}
int main(){
    string s = "abcabcbb";
    cout<<solve(s);
    return 0;
}