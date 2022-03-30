#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int j=nums.size()-1;
    //find the first not increase (3 2 6 5 4)->find 2  
    while (j>0 && nums[j-1]>=nums[j])
        j--;
    if (j>0)
    {
        int i=nums.size()-1;
        //right to left find the first bigger num than nums[j-1]
        while (i>=0 && nums[j-1]>=nums[i])
            i--;
        swap(nums[j-1],nums [i]);
    }
    reverse(nums.begin()+j, nums.end());
}
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
int main()
{
    vector<int> nums={1,2,3};
    nextPermutation(nums);
    print_list(nums);
    return 0;
}