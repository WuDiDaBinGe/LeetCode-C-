#include<bits/stdc++.h>
using namespace std;
/*
从一个仅有r e d组成的字符串s
s中有多少字串满足r e d字符个数严格相等。
*/
int main()
{
   string s; cin>>s;
   int n = s.size();
   vector<int> prefix_r(n + 1), prefix_e(n + 1), prefix_d(n + 1);
   for(int i = 0; i < n; ++i) {
        if(s[i] == 'r') {
            prefix_r[i + 1] = prefix_r[i] + 1;
        } else {
            prefix_r[i + 1] = prefix_r[i];
        }
        if(s[i] == 'e') {
            prefix_e[i + 1] = prefix_e[i] + 1;
        } else {
            prefix_e[i + 1] = prefix_e[i];
        }
        if(s[i] == 'd') {
            prefix_d[i + 1] = prefix_d[i] + 1;
        } else {
            prefix_d[i + 1] = prefix_d[i];
        }
   }
   int res = 0;
   for(int i = 0; i <= n -3; ++i) {
        for(int j = i + 2; j < n; ++j) {
            int count_r = prefix_r[j + 1] - prefix_r[i];
            int count_e = prefix_e[j + 1] - prefix_e[i];
            int count_d = prefix_d[j + 1] - prefix_d[i];
            if(count_r == count_e && count_e == count_d) res++;
        }
   }
   cout<<res<<endl;
   return 0;
}