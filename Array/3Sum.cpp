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
vector<int> twoSum(vector<int>& nums, int target, int start) {
    vector<int> tmp={-1,-1};
    unordered_map<int,int> num_index;
    for (int i = start; i < nums.size(); i++)
        num_index[nums[i]]=i;
    for (int i = start; i < nums.size(); i++)
    {
        int gap=target - nums[i];
        if(num_index.count(gap)&&num_index[gap]>i)
        {
            tmp[0]=i;
            tmp[1]=num_index[gap];
            break;
        }
    }
    return tmp;
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // num‘s index in nums
        vector<int> tmp = twoSum(nums,0-nums[i],i+1);
        if (tmp[0] != -1 && tmp[1] != -1){
            tmp.insert(tmp.begin(),i);
            vector<int> result_line;
            for (int j = 0; j < tmp.size(); j++)
                result_line.push_back(nums[tmp[j]]);
            int endIndex=result.size()-1;
            if(result.size()>0){
                //triple is same: avoid repeat element 
                if(result_line[0]!=result[endIndex][0] || result_line[1]!=result[endIndex][1] ||result_line[2]!=result[endIndex][2])
                    result.push_back(result_line);
            }
            else
                result.push_back(result_line);
        }  
    }
    for (int i = 0; i < result.size(); i++)
        print_list(result[i]);
    return result;
}
int main()
{
    vector<int> nums={-2,0,1,1,2};
    threeSum(nums);
    return 0;
}