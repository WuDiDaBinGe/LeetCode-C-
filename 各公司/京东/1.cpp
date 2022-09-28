#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<vector<int>> matrix(n, vector<int>(n));
   int cur_ji = 1, cur_ou = 2;
   for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            // ji ou ji ...
            for(int j = 0; j < n; ++j) {
                if(j % 2 == 0) {
                    matrix[i][j] = cur_ji;
                    cur_ji += 2;
                }
                else {
                    matrix[i][j] = cur_ou;
                    cur_ou += 2;
                }
            }
        } else {
            for(int j = 0; j < n; ++j) {
                if(j % 2 == 0) {
                    matrix[i][j] = cur_ou;
                    cur_ou += 2;
                }
                else {
                    matrix[i][j] = cur_ji;
                    cur_ji += 2;
                }
            } 
        }
   }
   for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout<<matrix[i][j];
            if(j < n - 1)
                cout<<" ";
        }
        cout<<endl;
   }
   return 0;
}