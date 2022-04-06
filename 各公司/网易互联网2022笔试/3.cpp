#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
// 末尾0个数 转化为找2*5的对数 转化为求因数5的个数，一般来说2的个数会比5多
int tailZero(int n) {
    if(n == 0) return 1;
    int res = 0;
    while(n % 10 == 0) {
        res += 1;
        n = n / 10;
    }
    return res;
}
bool check(int a, int b, int k) {
    int azero = tailZero(a);
    int bzero = tailZero(b);
    return (azero + bzero) >= k ? true : false;
}
int main() {
    int n, k; cin>>n>>k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    string s;cin>>s;
    int left = 0, right = 0;
    long long red_num = 1, blue_num = 1;
    int res = 200010;
    while (right < n) {
        if(s[right] == 'B')
            blue_num *= nums[right];
        else
            red_num *= nums[right];
        right++;
        while (check(blue_num, red_num, k)) {
            res = min(res, right - left);
            if(s[left] == 'B')
                blue_num /= nums[left];
            else
                red_num /= nums[left];
            left++;
        }
        
    }
    cout<<res<<endl;
    return 0;
}