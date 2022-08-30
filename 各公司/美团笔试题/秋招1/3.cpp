#include<bits/stdc++.h>
using namespace std;
int min_res = INT_MAX;
int n;
unordered_map<int, int> mp;
void dfs(int index, int count, vector<vector<int>> kinds) {
    // valid
    if(index <= n) {
        for(auto k_v:mp) {
            if(mp[k_v.first] > n / 2) {
                min_res = min(count, min_res);
                break;
            }
        }
        return;
    } 
    // purne 
    
    // bu zhuan 
    dfs(index + 1, count, kinds);
    // fan zhuan
    mp[kinds[index][0]]--;
    mp[kinds[index][1]]++;
    dfs(index + 1, count + 1, kinds);
    mp[kinds[index][0]]++;
    mp[kinds[index][1]]--;
}
int main()
{
   cin>>n;
   vector<vector<int>> kinds(n, vector<int>(2, 0));
   vector<int> cur_state(n, 0);
   for(int i = 0; i < n; ++i) {
        cin>>kinds[i][0];
        cur_state[i] = kinds[i][0];
        mp[kinds[i][0]]++;
   }
   for(int i = 0; i < n; ++i)
        cin>>kinds[i][1];
   dfs(0, 0, kinds);
   if(min_res == INT_MAX) 
        cout<<-1<<endl;
   else
        cout<<min_res<<endl; 
   return 0;
}