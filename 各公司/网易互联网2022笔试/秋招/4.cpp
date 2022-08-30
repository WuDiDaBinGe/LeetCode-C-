#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
/*
dp(i) = (dp(i - 1)* dp(i -2))的平方
其中第一项为a 第二项为b
*/
int main()
{
   long long a, b, n;
   cin>>a>>b>>n;
   long long dp_1, dp_2;
   dp_1 = a;
   dp_2 = b;
   for(int i = 3; i <= n; ++i) {
      long long num = (dp_1 * dp_2)  % mod;
      dp_1 = dp_2;
      dp_2 = (num * num) % mod;
   }
   cout<<dp_2<<endl;
   return 0;
}