#include<bits/stdc++.h>
using namespace std;

int main()
{
   int T; cin>>T;
   for(int n = 0; n < T; ++n) {
        int x, y; cin>>x>>y;
        int a = (x + y) / 3;
        int num = min(x, y);
        num = min(num, a);
        cout<<num<<endl;
   }
   return 0;
}