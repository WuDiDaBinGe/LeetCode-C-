#include<bits/stdc++.h>
using namespace std;

int countOne(int n) {
    int res = 0;
    while(n) {
        res++;
        n = (n - 1) & n;
    }
    return res;
}
// 遍历每个数字判断每个数字中1的个数
vector<int> countBits(int n) {
    vector<int> res;
    for(int i = 0; i <= n; ++i)
        res.push_back(countOne(i));
    return res;
}

// 动态规划 利用最高有效位 1010 中1的个数位 1010 - 1000 = 010的1的个数加1
vector<int> countBits1(int n) {
    vector<int> res(n + 1, 0);
    res[0] = 1;
    int hightBits = 0;
    for(int i = 1; i <= n; ++i) {
        if((i & (i - 1)) == 0) {
            hightBits = i;
            res[i] = 1;
        } else {
            res[i] = res[i - hightBits] + 1;
        }
    }
    return res;
}
// 动态规划 最低有效位
vector<int> countBits2(int n) {
    vector<int> res(n + 1, 0);
    res[0] = 0;
    for(int i = 1; i <= n; ++i) {
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}
int main() {
    return 0;
}