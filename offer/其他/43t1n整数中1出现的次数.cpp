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
            if(nstr[i] == '0') {
                res += n * a1;
            } else {
                res += (n - 1) * a1;
                // 目前有多少
                if(nstr[i] > '1') res += a1;
                else if(nstr[i] == '1') {
                    afterNum = stoi(nstr.substr(i + 1));
                    res += (afterNum + 1);
                }
            }
        }
        d *= 10;
        a1 *= 10;
    }
    return res;
}
//递归方法
int countDigitOne2(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    string strn = to_string(n);
    int top = strn[0] - '0';
    int digit = pow(10, strn.size() -  1);
    int remain = n % digit;
    if(top == 1){
        // 后面位置上的1 （前两项） + 最高位置上的1的个数(最后一项)
        return countDigitOne2(digit - 1) + countDigitOne2(remain) + (remain + 1);  
    } else {
        return countDigitOne2(digit - 1) * top  + countDigitOne2(remain) + digit;
    }

}
int main() {
    cout<<countDigitOne2(824883294)<<endl;
    cout<<"********"<<endl;
    cout<<countDigitOne1(824883294)<<endl;
    return 0;
}