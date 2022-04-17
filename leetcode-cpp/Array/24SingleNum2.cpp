#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
/*自己的思路 即将上一题的count=1改为count=2即可*/
/*排序+遍历*/
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int temp = nums[0];
    int count =2;   // 记录是否有两个
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]==temp) {
            count--;
        }
        // 不等于上一个数
        else {
            // 如果count还未减完 代表不是出现的两次单独的数返回
            if(count!=0)
                return temp;
            // count 为0 表示数据数字出现两次
            else
                count = 2;
            temp = nums[i];
        }
    }
    // 最后都没返回 是最后一个值
    return temp;
}