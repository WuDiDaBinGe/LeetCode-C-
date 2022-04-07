#include<bits/stdc++.h>
using namespace std;
vector<int> PATH;
void dfs(int index, int num, int n, int m) {
    // 边界
    if(index > n) {
        if(num == m) {
            for(int i = 0; i < m; i++) {
                cout<<PATH[i]<<" ";
            }
            cout<<endl;
        }
        return;
    } 
    // valid
    if(num == m) {
        for(int i = 0; i < m; i++) {
            cout<<PATH[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // purne
    // make choice
    // get
    PATH.push_back(index);
    dfs(index +1, num + 1, n, m);
    PATH.pop_back();
    // no get
    dfs(index + 1, num, n, m); 
}
int main() {
    int n, m;
    cin>>n>>m;
    dfs(1, 0, n, m);
    return 0;
}