#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
string S;
int n, m;
int res = 0, sub_max_len = -1;
void dfs(int last_index) {
   // border
   if(last_index == n) {

      res++;
      return;
   }
   // valid
   if(last_index > n) return;
   // purne

   // choice
   for(int i = last_index; i < last_index + sub_max_len; ++i) {
      string s = S.substr(last_index, i - last_index + 1);
      if(mp.find(s) == mp.end() || mp[s] <= 0) continue;
      mp[s]--;
      dfs(i + 1);
      mp[s]++;
   }
}
int main()
{
   
   cin>>n>>m;
   cin>>S;
   vector<int> subs_len(m);
   for(int i = 0; i < m; ++i)
      cin>>subs_len[i];
   for(int i = 0; i < m; ++i) {
      string sub; cin>>sub;
      int len = sub.size();
      mp[sub]++;
      sub_max_len = max(sub_max_len, len);
   }
   dfs(0);
   cout<<res<<endl;
   return 0;
}