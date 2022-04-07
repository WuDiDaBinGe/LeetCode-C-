#include<bits/stdc++.h>
using namespace std;
int main() {
    int T; cin>>T;
    for(int t = 0; t < T; t++) {
        int n; cin>>n;
        vector<int> left(n + 1, 0), right;
        for(int i = 0; i < n; i++) 
            cin>>left[i];
        sort(left.begin(), left.end());
        int scount = n, tcount = 0;
        while(tcount == n && scount == 0) {

        }
    }
    return 0;
}