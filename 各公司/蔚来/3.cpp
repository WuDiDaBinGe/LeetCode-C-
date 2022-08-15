#include<bits/stdc++.h>
using namespace std;
int k, sum, t = 1;

int main()
{
   cin>>k;
   string s; cin>>s;
   int n = s.size();
   s = " " + s;
   cout<<s<<endl;
   vector<char> ans[n + 1];
   vector<int> cnt(n + 1);
   while(sum < k) {
        sum = 1;
        ans[t].push_back(s[t]);
        cnt[t]++;
        if(t == n) t == 1;
        else t++;
        for(int i = 1; i <= n; ++i) {
            sum *= cnt[i];
        }
        cout<<sum<<endl;
   }
   cout<<"yxb"<<endl;
   for (int i = 0; i <= n; i++) {
        for(int j =0; j < ans[i].size(); j++) {
            cout<<ans[i][j];
        }
   }
   return 0;
}