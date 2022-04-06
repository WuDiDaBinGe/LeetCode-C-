#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    vector<int> times(n, 0);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>times[i];
        sum += times[i];
    }
    cout<<sum/2<<endl;
    return 0;
}