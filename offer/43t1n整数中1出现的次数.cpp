#include<bits/stdc++.h>
using namespace std;
// 暴力超时
int getOne(int num) {
    string str = to_string(num);
    int count = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '1')
            count++;
    }
    return count;
}
int countDigitOne(int n) {
    int res = 0;
    for(int i = 1; i <=n; i++) {
        res += getOne(i);
    }
    return res;
}
// 记录每个进制位上的 1 的个数
int countDigitOne1(int num) {
    string nstr = to_string(num);
    int res = 0;
    int d = 10, a1 = 1; 
    int afterNum = 0;
    for(int i = nstr.size() - 1; i >= 0; --i) {
        int n = (num - a1) / d + 1;
        cout<<n<<"xx"<<endl;
        if(i == nstr.size() - 1) {
            res += n  * a1;
        } else{
            res += (n - 1) * a1;
            res += afterNum + 1;
        }
        d *= 10;
        a1 *= 10;
        afterNum = stoi(nstr.substr(i));
    }
    return res;
}
int main() {
    cout<<countDigitOne(100)<<endl;
    cout<<"********"<<endl;
    cout<<countDigitOne1(100)<<endl;
    return 0;
}