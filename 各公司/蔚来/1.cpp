#include<bits/stdc++.h>
using namespace std;

int main()
{
   int N; cin>>N;
   vector<int>  nums(N);
   for(int i = 0; i < N; ++i) {
        cin>>nums[i];
   }
   int res = 0;
   int d1 = 0, d2 = 0;
   for(int i = 0; i < N; ++i) {
        if(d1 <= d2) {
            d1 += nums[i];
        } else {
            d2 += nums[i];
        }
   }
   cout<<max(d1, d2)<<endl;;
   return 0;
}