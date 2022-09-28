#include<bits/stdc++.h>
using namespace std;
/*
 给你一个数组如[3,2,1] 需要多少次变换到[1,2,3]
 一次变化为让一个数字 +1, 另一个数字-1，每次变化都要是一个排列(既1-n的数字没有重复)
 需要输出变化次数 以及 k行数字 每一行为变化 第一个序号的数字+1 第二个序号数字-1
*/
int main()
{
   int k = 0;
   int n; cin>>n;
   vector<int> nums(n);
   vector<int> target(n);
   for(int i = 0; i < n; ++i) {
        cin>>nums[i];
        target[i] = nums[i];
   }
   sort(target.begin(), target.end());
   vector<int> op_count;
   int max_add = 0, max_plus = 0;
   for(int i = 0; i < n; ++i) {
        int count = target[i] - nums[i];
        if(count > 0) max_add = max(max_add, abs(count));
        if(count < 0) max_plus = max(max_plus, abs(max_plus)); 
        op_count.push_back(count);
   }
   if(max_add == 0 && max_plus == 0) {
        cout<<0<<endl;
        return 0;
   } 
   vector<pair<int, int>> ops;

   
   return 0;
}