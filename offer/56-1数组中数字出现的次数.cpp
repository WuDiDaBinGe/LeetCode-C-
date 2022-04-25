#include<bits/stdc++.h>
using namespace std;
// 使用异或运算
vector<int> singleNumbers(vector<int>& nums) {
    int eor = 0;
    for(int num : nums)
        eor ^= num;
    // lowbits操作
    int rightOne = eor & (-eor);
    int eor_ = 0;
    for(int num : nums) {
        if((num & rightOne) == 0)
            eor_ ^= num;
    } 
    int a = eor_ ^ eor;
    int b = a ^ eor;
    return {a, b};
}
int main() {
    return 0;
}