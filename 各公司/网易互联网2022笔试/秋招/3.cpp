#include<bits/stdc++.h>
using namespace std;
/*
一个数组中选择k个数字
使其按位与的结果最大
*/
int count1(uint32_t n) {
    int res = 0;
    while(n) {
        res++;
        n = (n - 1) & n; // 每次进行一次这样的操作就会把最右边的1变成0
    }
    return res;
}
int main()
{
   int n, k;
   cin>>n>>k;
   vector<int> nums(n);
   for(int i = 0; i < n; ++i) {
        cin>>nums[i];
   }
   int maxValue = 0, cnt = 0, state = 1 << n;
   for(int i = pow(2, k) - 1; i < state; i++) {
        int cur = -1;
        if(count1(i) != k) continue;
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1 == 1) {
                cur &= nums[j];
                
            }
        }
        maxValue = max(maxValue, cur);
   }
   cout<<maxValue<<endl;
   return 0;
}