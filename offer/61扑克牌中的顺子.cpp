#include<bits/stdc++.h>
using namespace std;
bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int zero = 0;
    for(int i = 0; i < 5; i++) {
        if(nums[i] == 0) zero++;
        else {
            if(i == 0 || nums[i - 1] == 0 || nums[i] == nums[i - 1] + 1) continue;
            else{
                int gap = nums[i] - nums[i - 1] - 1;
                if(gap < 0) {
                    return false;
                }
                else if(gap <= zero) {
                    zero -= gap;
                    continue;
                } else
                    return false;
            }
        }
    }
    return true;
}
// 优化 一共五张牌  
// 1. 排序先判别重复 2. 使用最大值 - nums[joker] < 5 则能组成顺子
bool isStraight1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int joker = 0;
    for(int i = 0; i < 5; i++) {
        if(nums[i] == 0){
            joker++;
            continue;
        } 
        if(i > 0 && nums[i] == nums[i - 1]) return false;
    }
    return nums[4] - nums[joker] < 5;
}
int main() { 
    vector<int> a = {0,0,1,2,3};
    cout<<isStraight1(a)<<endl;
    return 0;
}