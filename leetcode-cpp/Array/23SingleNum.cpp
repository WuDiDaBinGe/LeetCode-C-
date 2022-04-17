#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
/*自己的思路*/
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int temp = nums[0];
    int count =1;   // 记录是否有两个
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
                count = 1;
            temp = nums[i];
        }
    }
    // 最后都没返回 是最后一个值
    return temp;
}
/*
    异或 不仅能处理出现两次的情况，也可以处理出现偶数次的情况
    0 异或 a = a
    a 异或 a = 0
    主要异或满足交换律和结合律
*/
int singleNumber2(vector<int>& nums) {
    int res = 0;
    for(int i=0;i<nums.size();i++) {
        res = res ^ nums[i];
    }
    return res;
}
int main(){
    return 0;
}
