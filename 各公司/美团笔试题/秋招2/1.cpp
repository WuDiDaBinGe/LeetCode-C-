#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n, m; cin>>n>>m;
   string S, s;
   cin>>S>>s;
   int res = 0;
   for(int i = 0; i <= n - m; ++i) {
        bool flag = true;
        for(int j = 0; j < m; ++j) {
            if(s[j] == '*') continue;;
            if(s[j] != S[i + j]) {
                flag = false; 
                break;
            } 
        }
        if(flag) res++;
   }
   cout<<res<<endl;
   return 0;
}