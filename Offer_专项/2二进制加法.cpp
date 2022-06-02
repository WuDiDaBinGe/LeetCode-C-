#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i = 0; i < n; ++i) {
            if(i < a.size()) carry += a[i] == '1';
            else carry += 0;
            if(i < b.size()) carry += b[i] == '1';
            else carry += 0;
            //cout<<carry<<endl;
            // 这一位是取余 进制2
            res.push_back(carry % 2 +'0');
            // 进位是除以 进制2
            carry = carry / 2;
        }
        if(carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};