#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result={};
    if (nums.size()<3)
        return result;
    //sorted array
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size()-2; i++)
    {
        // two point
        int left=i+1,right=nums.size()-1;
        if(nums[i]>0)
            return result;
        // repeat element is only check the first element
        if(i>0 && nums[i]==nums[i-1])
            continue;
        while(left<right)
        {
            if (nums[i]+nums[left]+nums[right] == 0)
            {
                vector<int> result_line;
                result_line.push_back(nums[i]);
                result_line.push_back(nums[left]);
                result_line.push_back(nums[right]);
                result.push_back(result_line);
                while(left<right&&nums[left]==nums[left+1])
                    left++;
                while(left<right&&nums[right-1]==nums[right])
                    right--;
                left++;
                right--;
            }
            else if (nums[i]+nums[left]+nums[right]<0)
                left++;
            else
                right--;
        }
    }
    return result;
}
int main()
{
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for(int i=0;i<res.size();i++)
        print_list(res[i]);
    return 0;
}