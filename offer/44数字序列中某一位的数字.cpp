#include<bits/stdc++.h>
using namespace std;
// n表示从digits开始需要的个数
// n = 21 digits = 2 表示从“10”开始的再数21位
int help(int n, int digits) {
    if(n <= 9 && digits == 1) return n;
    // 求该数位的一共有多少长度
    long long unit = digits * pow(10, digits - 1);
    long long length = unit * (digits == 1 ? 10 : 9);
    int res = -1;
    // cout<<n<<" "<<digits<<" "<<length<<endl;
    // 在digits位数 组成的范围内
    if(n <= length - 1) {
        int num = n / unit;
        n = n - num * unit;
        int mod = n % digits;
        if(mod == 0) return num + 1;
        else {
            string count = to_string(n / digits);
            return count[mod - 1] - '0';
        }
    }
    // 不再范围内继续递归 
    else{
        n = n - length;
        return help(n, digits + 1);
    }
}
int findNthDigit(int n) {
    return help(n, 1);
}
int main() {
    cout<<findNthDigit(13)<<endl;
    cout<<findNthDigit(19)<<endl;
    return 0;
}