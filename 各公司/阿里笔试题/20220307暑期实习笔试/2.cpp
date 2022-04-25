#include<bits/stdc++.h>
using namespace std;
void dfs() {

}
int main() {
    int n; cin>>n;
    vector<int> nums(n, 0);
    int sum = 0;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    cout<<nums[n - 1]<<endl;
    return 0;
}