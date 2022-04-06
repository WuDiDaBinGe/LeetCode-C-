#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> nums(n, 0), temp(n,0);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
        temp[i] = nums[i];
    }
    if(n <= 2) {
        cout<<0<<endl;
        return 0;
    }

    int i = n - 2;
    while (i >= 0 && nums[i] > nums[i + 1]) {
        i--;
    }
    if(i <= 0) {
        cout<<0<<endl;
        return 0;
    }
    int res = 0;
    for(int j = 1; j <= i ; j++) {
        if(nums[j] <= nums[j - 1]) {
            res += nums[j - 1]  - nums[j] + 1;
            nums[j] = nums[j - 1] + 1;
        }
    }
    if(nums[i] <= nums[i + 1]) res += (nums[i + 1] - nums[i] + 1);
    int res1 = 0;
    for(int j = 1; j <= i + 1; j++) {
        if(temp[j] <= temp[j - 1]) {
            res1 += temp[j - 1]  - temp[j] + 1;
            temp[j] = temp[j - 1] + 1;
        }
    }
    cout<<min(res, res1)<<endl;
    return 0;
}