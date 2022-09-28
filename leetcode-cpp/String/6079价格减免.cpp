#include<bits/stdc++.h>
using namespace std;
string discountPrices(string sentence, int discount) {
    stringstream ss(sentence);
    string x;
    string res;
    while(ss>>x) {
        if(check(x)) {
            double price = stod(x.substr(1));
            price = price * (1.0 - discount * 0.01);
            stringstream p_str;
            // 固定小数点之后几位输出
            p_str<<setiosflags(ios::fixed)<<setprecision(2)<<price;
            res += ("$" + p_str.str() + " ");
        } else{
            res += (x + " ");
        }
    }
    res.pop_back();
    return res;
}
bool check(string& s) {
    int n = s.size();
    if(n < 2) return false;
    if(s[0] != '$') return false;
    for(int i = 1; i < n; ++i) {
        if(s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}