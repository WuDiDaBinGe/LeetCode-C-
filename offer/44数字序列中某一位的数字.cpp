#include<bits/stdc++.h>
using namespace std;
// n表示从digits开始需要的个数
// n = 21 digits = 2 表示从“10”开始的再数21位
int help(int n, int digits) {
    if(n <= 9 && digits == 1) return n;
    // 求该数位的一共有多少长度
    long long unit = digits * pow(10, digits - 1);
    long long length = unit * (digits == 1 ? 10 : 9);
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
// 优化递归
int help(int n, int digits) {
    if(n <= 9 && digits == 1) return n;
    // 求该数位的一共有多少长度
    long long unit = digits * pow(10, digits - 1);
    long long length = unit * (digits == 1 ? 10 : 9);
    // cout<<n<<" "<<digits<<" "<<length<<endl;
    // 在digits位数 组成的范围内
    if(n <= length - 1) {
        int num = n / digits;
        int mod = n % digits;
        num += pow(10, digits - 1);
        string count = to_string(num);
        return count[mod] - '0';
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
// 另一种简单思路 把每一位数字字符都补成目前位数的数组宽度
// 补位之后返回那么返回下标k//i的数 的 第 k%i 位即可
int findNthDigit1(int n) {
    long long n_ = n;
    for(long long i = 1; ; i++) {
        if(n_ < i * pow(10, i)) {
            return to_string(n_ / i)[n_ % i] - '0';
        }
        // 补齐后移
        n_ += pow(10, i);
    }
}
int main() {
    cout<<findNthDigit(13)<<endl;
    cout<<findNthDigit(19)<<endl;
    return 0;
}