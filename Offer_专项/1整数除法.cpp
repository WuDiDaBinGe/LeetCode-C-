#include<bits/stdc++.h>
using namespace std;
// 快速乘法 判断 z * b >= a  a, b < 0
bool quickMul(int a, int b, int z) {
    int res = 0;
    while(z) {
        if(z & 1) {
            // res +b >= a
            if(res < a - b) return false;
            res = res + b;
        }
        // z == 1就不用加了
        if(z != 1) {
            // b + b >= a
            if(b < a - b) return false;
            b += b ;
        }
        z = z >> 1;
    }
    return res >= a;
}
int divide(int a, int b) {
    //特殊情况 
    if(a == 0) return 0;
    if(b == 1) return a;
    if(a == INT_MIN && b == -1) return INT_MAX;
    if(b == -1) return -a;
    if(b == INT_MIN && a == INT_MIN) return 1;
    if(b == INT_MIN && a != INT_MIN) return 0;
    bool flag = false;
    // 为了防止溢出 将a b 全部转化为负数
    if(a > 0) a = -a, flag = !flag;
    if(b > 0) b = -b, flag = !flag;
    int res = 0;
    // 快速减法 实现
    // 二分查找 res
    int left = 0, right = INT_MAX;
    while(left <= right) {
        int mid = left + ((right - left)>>1);
        cout<<mid<<endl;
        if(quickMul(a, b, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return flag ? -right:right;
}
int main() {
    // cout<<divide(15, 2)<<endl;
    // cout<<divide(7, -3)<<endl;
    // cout<<divide(0, 1)<<endl;
    cout<<divide(2147483647, 2)<<endl;
    cout<<INT_MIN<<endl;
    return 0;
}