#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long getNum(string &s, int x) {
    long long res = 0;
    for (char c: s) {
        res *= x;
        if (c >= '0' && c <= '9') {
            res = (res + c - '0') % MOD;
        } else {
            res = (res + c - 'A' + 10) % MOD;
        }
    }
    return res;
}

int main() {
    int x = 0;
    string s;
    cin >> s;
    set<long long> st;
    for (auto &c: s) {
        if (c >= '0' && c <= '9') {
            x = max(x, c - '0' + 1);
        } else if (c >= 'A' && c <= 'F') {
            x = max(x, c - 'A' + 11);
        }
    }
    if (x == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (; x <= 16; x++) {
        st.insert(getNum(s, x) % MOD);
    }
    for (auto p: st)
        cout << p << endl;
    cout<<MOD<<endl;
    return 0;
}