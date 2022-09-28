#include<bits/stdc++.h>
using namespace std;
/*
step 1：两数进行与运算可以产生进位的信息
step 2：运算后执行左移1位就是每轮需要进位的方案
step 3：两数进行异或运算可以产生非进位的加和结果
step 4：将移位后的进位结果与非进位结果继续重复 step 1 - step 3 的步骤，直到不再产生进位为止
*/
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