#include<bits/stdc++.h>
using namespace std;
// 统计每一位上1的个数 除以3的个数有余数 说明那一个数改位有1
int singleNumber(vector<int>& nums) {
    int dits[32];
    memset(dits, 0, sizeof(dits));
    for(int i = 0; i < nums.size(); ++i) {
        int n = nums[i];
        int count = 0;
        // 注意n可能为负数 必须负数右移补1 导致最后为-1 需要添加条件count < 32
        while(n && count < 32) {
            if(n & 1 == 1) dits[count]++;
            n = n >> 1;
            count++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; ++i) {
        dits[i] = dits[i] % 3;
        if(dits[i] == 1)
        //直接移位操作
            res = res | (1 << i);
    }
    return res;
}
int main() {
    
    return 0;
}