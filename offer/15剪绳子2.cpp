#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
// 贪心
// 使用循环取余 或者 快速幂取余
int cuttingRope(int n) {
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    int p = 1000000007;
    int t3 = n / 3;
    long long res = 1;
    for(int i = 1; i < t3; i++) {
        res = (res * 3) % p; 
    }
    if(n % 3 == 1) 
        res = (res * 4) % 1000000007;
    else if(n % 3 == 0)
        res = (res * 3) % 1000000007;
    else if(n % 3 == 2)
        res = (res * 6) % 1000000007;
    return res; 
}
// 快速幂求余
int cuttingRope2(int n) {
    if(n < 2)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;
    int p = 1000000007;
    int t3 = n / 3 - 1;
    long long res = 1;
    long long x = 3;
    while (t3 > 0) {
        if(t3 % 2) res = (res * x) % p;
        x = (x * x) % p;
        t3 = t3 / 2; 
    }
    
    if(n % 3 == 1) 
        res = (res * 4) % p;
    else if(n % 3 == 0)
        res = (res * 3) % p;
    else if(n % 3 == 2)
        res = (res * 6) % p;
    return (int)res;  
}
int main() {
    cout<<cuttingRope(1000)<<endl;
    cout<<cuttingRope2(1000)<<endl;
    return 0;
}