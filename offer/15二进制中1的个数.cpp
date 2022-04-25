#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
// 移位原数
int hammingWeight(uint32_t n) {
    int res = 0;
    while(n) {
        cout<<n<<endl;
        if(n & 1)
            res++;
        n = n >> 1;
        
    }
    return res;
}
// 移位flag检查是否有1
int hammingWeight2(uint32_t n) {
    int res = 0;
    uint32_t flag = 1;
    while(flag) {
        if(n & flag)
            res++;
        flag = flag << 1;
    }
    return res;
}
int hammingWeight3(uint32_t n) {
    int res = 0;
    while(n) {
        res++;
        n = (n - 1) & n; // 每次进行一次这样的操作就会把最右边的1变成0
    }
    return res;
}
int main() {
    // uint32_t num; cin>>num;
    // cout<<num<<endl;
    cout<<hammingWeight(11111111111111111111111111111101)<<endl;
    cout<<hammingWeight(4294967293)<<endl;
    return 0;
}