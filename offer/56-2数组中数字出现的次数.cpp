#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    vector<int> hash(32, 0);
    for(int num : nums) {
        int res = 0;
        while(num){
            if(num & 1 == 1) hash[res]++;
            num = num>>1;
            res++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++) {
        if(hash[i] % 3 == 1) res += pow(2, i);
    }
    return res;
}
int main() {
    vector<int> nums = {9,1,7,9,7,9,7};
    cout<<singleNumber(nums)<<endl;
    return 0;
}