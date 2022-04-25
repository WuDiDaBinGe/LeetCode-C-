#include<bits/stdc++.h>
using namespace std;
int main() {
    int T; cin>>T;
    for(int t = 0; t < T; t++) {
        int n; cin>>n;
        vector<int> left(n + 1, 0), right;
        for(int i = 1; i <= n; i++) 
            cin>>left[i];
        sort(left.begin() + 1, left.end());
        int res = 0;
        while (n >= 4) {
            res += min(left[1] + 2 * left[2] + left[n], 2 * left[1] + left[n - 1] + left[n]);
            n = n - 2;
        }
        if(n == 3) {
            res += (left[1] + left[2] + left[3]);
        } else if(n == 2) {
            res += left[2];
        }
        cout<<res<<endl;
    }
    return 0;
}