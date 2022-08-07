#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int> nums(n, 0);
   int zero = 0;
   vector<int> prefix_1(n + 1, 0);
   vector<int> prefix_n1(n + 1, 0);
   for(int i = 0; i < n; ++i) {
        cin>>nums[i];
        if(nums[i] == 0) zero++;
   }
   for(int i = 0; i < n; ++i) {
        if(nums[i] == 1) {
            prefix_1[i + 1] = prefix_1[i] + 1;
        } else {
            prefix_1[i + 1] = prefix_1[i];
        }
        if(nums[i] == -1) {
            prefix_n1[i + 1] = prefix_n1[i] + 1;
        } else {
            prefix_n1[i + 1] = prefix_n1[i];
        }
   }
   int r = n;
   for(int k = 1; k <= n; k++) {
        int p = prefix_1[k];
        int b = prefix_n1[n] - prefix_n1[k];
        r = min(r, p + b);
   } 
   cout<<r + zero<<endl;
   return 0;
}