#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> tmp;
    unordered_map<int,int> num_index;
    for (int i = 0; i < nums.size(); i++)
        num_index[nums[i]]=i;
    for (int i = 0; i < nums.size(); i++)
    {
        int gap=target - nums[i];
        if(num_index.count(gap)&&num_index[gap]>i)
        {
            tmp.push_back(i);
            tmp.push_back(num_index[gap]);
            break;
        }
    }
    return tmp;
}
int main()
{
    vector<int> nums={2,7,11,15};
    cout<<twoSum(nums,9)[0]<<endl;
    cout<<twoSum(nums,9)[1]<<endl;
    return 0;
}