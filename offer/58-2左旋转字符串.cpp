#include<bits/stdc++.h>
using namespace std;
string reverseLeftWords(string s, int n) {
    string a = s.substr(0, n);
    string b = s.substr(n);
    return b + a;
}
// 双指针
string reverseLeftWords(string s, int n) {
    int se = s.size();
    string a = s.substr(0, n);
    int l = 0, r = n;
    while (r < se) {
        s[l] = s[r];
        l++;
        r++;
    }
    for(int i = 0; i < n; i++) {
        s[l] = a[i];
        l++;
    }
    return s;
}
int main() {
    return 0;
}