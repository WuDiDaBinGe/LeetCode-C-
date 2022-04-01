#include<bits/stdc++.h>
using namespace std;
// 使用双指针
void getAns(vector<int>& nums, string sexstr) {
    int m = sexstr.size();
    int n = nums.size();
    int f0 = 0, f1 = 0;
    while(f0 < n && nums[f0] != 0)
        f0++;
    while(f1 < n && nums[f1] != 1)
        f1++;
    
    for(int i = 0; i < m; i++) {
        vector<int> flags = {-1 ,-1};
        if(sexstr[i] == 'M') {
            if(f1 < n) {
                printf("%d\n", f1 + 1);
                nums[f1]++;
                while(f1 < n && nums[f1] != 1) f1++;
            } else {
                printf("%d\n", f0 + 1);
                nums[f0]++;
                if(f0 < f1) f1 = f0;
                while(f0 < n && nums[f0] != 0) f0++;
            }
        } else {
            if(f0 < n) {
                printf("%d\n", f0 + 1);
                nums[f0]++;
                if(f0 < f1) f1 = f0;
                while(f0 < n && nums[f0] != 0) f0++;
            } else {
                printf("%d\n", f1 + 1);
                nums[f1]++;
                while(f1 < n && nums[f1] != 1) f1++;
            }
        }
    }
    return;
}
// 正确解法：使用两个优先队列 作为的下标
// 一个存储 0 人作为的下标 一个存储1人作为的下标
// 本题会卡cout 要换成printf
int main() {
    int T;cin>>T;
    for(int t = 0; t < T; t++) {
        int n, m; string sexstr, numstr;
        cin>>n; cin>>numstr;
        vector<int> nums(n, 0);
        priority_queue<int ,vector<int>, greater<int>> q0, q1;
        for(int i = 0; i < n; i++) {
            nums[i] = numstr[i] - '0';
            if(nums[i] == 0) q0.push(i);
            else if(nums[i] == 1) q1.push(i);
        }
        cin>>m;  cin>>sexstr;
        //getAns(nums, sexstr);
        for(int i = 0; i < sexstr.size(); i++) {
            int index = -1;
            if(sexstr[i] == 'M') {
                if(!q1.empty()) {
                    index = q1.top();q1.pop();
                    nums[index]++;
                } else {
                    index = q0.top(); q0.pop();
                    nums[index]++;
                    q1.push(index);
                }
            } else {
                if(!q0.empty()) {
                    index = q0.top(); q0.pop();
                    nums[index]++;
                    q1.push(index);
                } else {
                    index = q1.top();q1.pop();
                    nums[index]++;
                }
            }
            printf("%d\n", index + 1);
        }
    }
    return 0;
}