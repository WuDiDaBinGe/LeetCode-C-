#include<bits/stdc++.h>
using namespace std;
int n; 
vector<vector<int>> peoples;
vector<int> path;
int res = 0, suma = 0, sumd = 0;
void dfs(int index, int suma, int sumd, int sumad) {
    // border and valid
    if(index == n) {
        if(suma > 0 && sumd > 0) {
            res = max(res, sumad);
        }
        return ;
    }
    // make choice
    if(sumad < 0) return;
    // choose
    dfs(index + 1, suma + peoples[index][1], sumd + peoples[index][2], sumad + peoples[index][0]);
    // no choose
    dfs(index + 1, suma, sumd, sumad);
}
int main() {
    cin>>n;
    sort(peoples.begin(), peoples.end());
    reverse(peoples.begin(), peoples.end());
    for(int i = 0; i < n; i++) {
        int a,d; cin>>a>>d;
        peoples.push_back({a + d, a, d});
    }
    dfs(0, 0, 0, 0);
    cout<<res<<endl;
    return 0;
}