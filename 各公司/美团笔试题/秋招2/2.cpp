#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n, m;cin>>n>>m;
   stack<int> stk;
   map<int, int> mp;
   for(int i = 0; i < n; ++i) {
        mp[i + 1] = 0;
   }
   for(int i = 0; i < m; ++i) {
        int index; cin>>index;
        stk.push(index);
   }
   while(!stk.empty()) {
        int value = stk.top();stk.pop();
        auto iter = mp.find(value);
        if(iter != mp.end()) {
            cout<<value<<" ";
            mp.erase(iter);
        }
        
   }
   if(mp.size() > 0) {
        for(auto item:mp) {
            cout<<item.first<<" ";
        }
   }
   return 0;
}