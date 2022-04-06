#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,b;
    while (cin>>n) {
        cin>>m>>a>>b;
        if(a < b) swap(a, b);
        vector<int> weights(m, 0);
        int min_value = 1001, max_value = -1;
        for(int i = 0; i < m; i++) {
            cin>>weights[i];
            if(weights[i] <= min_value) min_value = weights[i];
            if(weights[i] >= max_value) max_value = weights[i];
         }
         if(min_value < b || max_value > a) {
             cout<<"NO"<<endl;
             continue;
         } else {
             if(n - m >= 2) {
                 cout<<"YES"<<endl;
                 continue;
             } else {
                 if(min_value == b || max_value == a) {
                     cout<<"YES"<<endl;
                     continue;
                 } else {
                     cout<<"NO"<<endl;
                     continue;
                 } 
             }
         }
    }
    return 0;
}