#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==val)
        {
            int j=i+1;
            while (nums[j]==val&&j<nums.size())
                j++;
            if(j<nums.size())
            {
                nums[i]=nums[j];
                nums[j]=val;
            }
            else
                return i;
        }
    }
}
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
int main()
{
    vector<int> nums={3,2,2,3};
    cout<<removeElement(nums,2)<<endl;
    print_list(nums);
    return 0;
}