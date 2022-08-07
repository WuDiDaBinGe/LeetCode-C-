#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n, m;
   cin>>n>>m;
   vector<vector<int>> G(m + 1);
   for(int i = 1; i <= n; ++i) {
        int c ;cin>>c;
        G[c].push_back(i);
   }
   vector<int> train, test;
   for(int i = 1; i <= m; ++i) {
        int mm = G[i].size();
        mm = (mm - 1) / 2 + 1;
        for(int j = 0; j < G[i].size(); ++j) {
            if(j < mm) train.push_back(G[i][j]);
            else test.push_back(G[i][j]);
        }
   }
   sort(train.begin(), train.end());
   sort(test.begin(), test.end());
   for (int i = 0; i < train.size(); i++) {
        cout<<train[i]<<" ";
   }
   cout<<endl;
   for (int i = 0; i < test.size(); i++) {
        cout<<test[i]<<" ";
   }
   return 0;
}