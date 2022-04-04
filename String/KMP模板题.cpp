#include<bits/stdc++.h>
using namespace std;
void genNext(string p, vector<int>& next) {
    int n = p.size();
    int j = 0; // 表示当前最大的子前缀长度
    next[0] = 0;
    //i表示表示后缀的结尾
    for(int i = 1; i < n ; i++) {
        while(j > 0 && p[j] != p[i]) {
            j = next[j - 1];
        }
        if(p[j] == p[i])
            j++;
        next[i] = j;
    }
}
void kmpCore(string s, string p) {
    int n = s.size();
    int m = p.size();
    if(m > n) return ;
    vector<int> next(m, 0);
    genNext(p, next);
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j > 0 && p[j] != s[i]) {
            j = next[j - 1];
        }
        if(p[j] == s[i])
            j++;
        if(j == m) {
            cout<<(i - m + 2)<<endl;
            // 字串存在多个位置
            j = next[j - 1];
        }
    }
    for(int i = 0; i < m; i++) {
        cout<<next[i]<<" ";
    }
}
int main() {
    string s, p; cin>>s>>p;
    kmpCore(s, p);
    return 0;
}