#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int index=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=val)
            nums[index++]=nums[i];
    }
    return index;
}
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
int main()
{
    vector<int> nums={0,1,2,2,3,0,4,2};
    cout<<removeElement(nums,2)<<endl;
    print_list(nums);
    return 0;
}