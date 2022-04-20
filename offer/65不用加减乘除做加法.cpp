#include<bits/stdc++.h>
using namespace std;
// 不适用四则运算完成加法 使用位运算
int add(int a, int b) {
    //因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止  
    while (b != 0) {
        //保存进位值，下次循环用
        int c = (unsigned int)(a & b) << 1; // 注意c++ 中的负数不能移位
        // 保存不进位值
        a = a ^ b;
        // 还有进位值， 再循环
        b = c;
    }
    return a;
}
int main() {
    return 0;
}