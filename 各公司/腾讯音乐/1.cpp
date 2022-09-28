#include<bits/stdc++.h>
using namespace std;
class Solution {
    int MOD = 1000000007;
public:
    int getSubarrayNum(vector<int>& a, int x) {
        int n = a.size();
        vector<int> num_5(n), num_2(n);
        for(int i = 0; i < n; ++i) {
            int t = a[i], count5 = 0, count2 = 0;
            if(t % 5 == 0) {
                while(t % 5 == 0) {
                    count5++;
                    t /= 5;
                }
            }
            if(t % 2 == 0) {
                while(t % 2 == 0) {
                    count2++;
                    t /= 2;
                }
            }
            num_5[i] = count5;
            num_2[i] = count2;
        }
        // 前缀和
        // vector<int> prefix5(n + 1), prefix2(n + 1);
        // for(int i = 1; i <= n; ++i) {
        //     prefix5[i] = prefix5[i - 1] + num_5[i - 1];
        //     prefix2[i] = prefix2[i - 1] + num_2[i - 1];
        // }
        // 滑动窗口
        int count2 = 0, count5 = 0;
        int left = 0, right = 0;
        int res = 0;
        while(right < n) {
            count2 += num_2[right];
            count5 += num_5[right];
            right++;
            while(min(count2, count5) >= x) {
                count2 -= num_2[left];
                count5 -= num_5[left];
                left++;
            }
            res++;
            res %= MOD;
        }
        int total = n * (n + 1) % MOD;
        total /= 2;
        return total - res;
    }
};