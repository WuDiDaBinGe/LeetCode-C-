#include<iostream>
#include<algorithm>
#include<vector>
#include "utils.cpp"
using namespace std;
void nextPermutation(vector<int>& nums) {
    int j = nums.size()-1;
    while (j>0&&nums[j-1]>=nums[j])
        j--;
    if (j>0)
    {
        int i=nums.size()-1;
        while (i>0&&nums[i]<=nums[j-1])
            i--;
        swap(nums[j-1],nums[i]);
    }
    reverse(nums.begin()+j,nums.end());
}
string getPermutation_1(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    for (int i = 1; i < k; i++)
        nextPermutation(nums);
    string result="";
    for (int i = 0; i < nums.size(); i++)
        result += to_string(nums[i]);
    return result;
}
/*算阶乘*/
int factor(int n){
    if(n==1) return 1;
    int result=1;
    for (int i = n; i >= 1; i--)
        result *= i;
    return result;
}
/*利用了康托解码的思路 定住一个 看剩下的(n-1)个值*/
/*n为1-n序列，k为第几个排列*/
string getPermutation(int n, int k) {
    
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);
    k--;
    string res="";
    while (nums.size()>1)
    {
        //从小到大第几个数
        int bright_num = k / factor(nums.size()-1);
        // 还剩多少个数
        k = k % (factor(nums.size()-1));
        res += to_string(nums[bright_num]);
        nums.erase(nums.begin()+bright_num);
    }
    return res;
}
/*反过来 求一个数字序列 是第几个全排序*/
int main()
{
    cout<<getPermutation(5,16)<<endl;
    return 0;
}