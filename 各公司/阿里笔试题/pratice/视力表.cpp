#include<bits/stdc++.h>
using namespace std;
#define Yu 998244353
#define ll long long
int N;
ll res = 0;
// a上 b下  c左 d右
void dfs(int index, vector<int>& nums) {
    //border
    if(index == N * N) {
        res++;
        return ;
    }
    for(int i = 0; i < 4; i++) {
        if(nums[i] <= 0) continue;
        nums[i]--;
        dfs(index + 1, nums);
        nums[i]++;
    }
}
int main() {
    vector<int> nums(4, 0);
    cin>>N>>nums[0]>>nums[1]>>nums[2]>>nums[3];
    dfs(0, nums);
    cout<<res % Yu<<endl;
    return 0;
}