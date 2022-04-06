#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += (abs(nums[i - 1] - i));
    }
    cout<<res<<endl;
    return 0;
}