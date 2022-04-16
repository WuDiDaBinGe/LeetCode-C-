#include<bits/stdc++.h>
using namespace std;
//
char firstUniqChar(string s) {
    int n = s.size();
    if(n == 0) return ' ';
    unordered_map<char, pair<int, int>> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]].first = i;
        mp[s[i]].second++;
    }
    int lowest = INT_MAX;
    for(auto kv:mp) {
        if(kv.second.second == 1 && kv.second.first < lowest) {
            lowest = kv.second.first;
        }
    }
    return lowest == INT_MAX ? ' ' : s[lowest];
}
int main() {
    return 0;
}