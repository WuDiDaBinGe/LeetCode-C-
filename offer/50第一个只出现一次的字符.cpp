#include<bits/stdc++.h>
using namespace std;
// 使用map记录
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
// 有序hash表
char firstUniqChar(string s) {
    // mp key:代表一个字符 int:0 表示出现多次 1表示出现一次
    unordered_map<char, int> mp;
    // 记录字符出现的顺序
    vector<char> vec;
    for(char c:s) {
        if(mp.find(c) == mp.end())
            vec.push_back(c);
        mp[c] = mp.find(c) == mp.end();
    }
    for(char c : vec) {
        if(mp[c]) return c;
    }
    return ' ';
}
int main() {
    return 0;
}