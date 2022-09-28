#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> nums){
    int n = nums.size();
    vector<int> res(n);
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(nums[j] > nums[i]) {
                res[i] = (j - i);
                break;
            }
        }
    }
    for(int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    return res;
}
int main(){
    vector<int> nums1 = {30,40,50,60};
    vector<int> res = solve(nums1);
    return 0;
}