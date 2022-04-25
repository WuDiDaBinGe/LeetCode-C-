#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
// sorted() ->3-for 
vector<vector<int>> fourSum1(vector<int>& nums,int target) {
    vector<vector<int>> result={};
    int length = nums.size();
    if (length<4)
        return result;
    //sorted array
    sort(nums.begin(),nums.end());
    for (int i = 0; i < length-3; i++)
    {
        if (i>0 && nums[i-1]==nums[i])
            continue;
        // Pruning optimization 
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
            break;
        if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) 
            continue;
        for (int j = i+1; j < length-2; j++)
        {
            if(j>i+1 && nums[j-1]==nums[j])
                continue;
            // Pruning optimization 
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target)
                break;
            if(nums[i]+nums[j]+nums[length-1]+nums[length-2] < target)
                continue;
            int left=j+1, right=length-1;
            while(left<right)
            {
                int sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target)
                {
                    vector<int> result_line;
                    result_line.push_back(nums[i]);
                    result_line.push_back(nums[j]);
                    result_line.push_back(nums[left]);
                    result_line.push_back(nums[right]);
                    result.push_back(result_line);
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum<target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}
//sort + hashmap 
vector<vector<int>> fourSum_haspmap(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int length = nums.size();
    if (length<4)
        return result;
    sort(nums.begin(),nums.end());
    unordered_map<int,vector<pair<int,int>>> cache;
    for(int i=0;i<length-1;i++)
        for(int  j=i+1;j<length;j++)
            cache[nums[i]+nums[j]].push_back(pair<int,int>(i,j));
    for(int c=0;c<length-1;c++)
    {
        for(int d=c+1;d<length;d++)
        {
            int query=target-nums[c]-nums[d];
            if(cache.find(query)==cache.end()) continue;
            const auto &vect = cache[query];
            for(int k=0;k<vect.size();k++)
            {
                if (c<=vect[k].second)
                    continue;           //avoid repeat 
                result.push_back({nums[vect[k].first],nums[vect[k].second],nums[c],nums[d]});
            }
        }
    }
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}
//sort + muiltmap

// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     vector<vector<int>> result={};
//     unordered_map<int,int> un_map;
//     if (nums.size()<4)
//         return result;
//     sort(nums.begin(),nums.end());
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i+1; j < nums.size(); j++)
//         {
            
//         }
//     }
// }
int main()
{
    vector<int> nums={1,0,-1,0,-2,2}; 
    vector<vector<int>> res=fourSum1(nums,0);
    for (int i = 0; i < res.size(); i++)
        print_list(res[i]);
    return 0;
}