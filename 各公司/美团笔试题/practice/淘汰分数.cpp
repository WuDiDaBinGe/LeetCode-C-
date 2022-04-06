#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, x, y;cin>>n>>x>>y;
    vector<int> scores(n, 0);
    for(int i = 0; i < n; i++) {
        cin>>scores[i];
    }
    sort(scores.begin(), scores.end());
    if(y == n) {
        cout<<scores[0] - 1<<endl;
        return 0;
    }
    int start = max(x, n - y);
    int end = min(y, n - x);
    int res = 10001;
    for(int i = start; i <= end; i++) {
        res = min(res, scores[i - 1]);
    }
    cout<<(res == 1000 ?-1:res)<<endl;
    return 0;
}