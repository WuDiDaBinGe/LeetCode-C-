#include<bits/stdc++.h>
using namespace std;
int main() {
    int res = 0;
    int n, x; cin>>n>>x;
    vector<int> scores(n, 0);
    for(int i = 0; i < n; i++)
        cin>>scores[i];
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());
    x = (x >= n) ? n : x;
    int i = x - 1;
    if(scores[i] != 0) {
        while (i + 1< n && scores[i] == scores[i + 1]) {
            i++;
        }
    }
    for(i; i >= 0; i--) {
        if(scores[i] != 0)
            break;
    }
    cout<<i + 1<<endl;
    return 0;
}