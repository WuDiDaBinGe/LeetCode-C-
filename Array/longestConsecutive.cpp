#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
/*Solve 1: hashmap */
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (int i = 0; i < nums.size(); i++)
        num_set.insert(nums[i]);
    long longestStreak=0;
    for (auto i:nums)
    {
        int currentStreak=1;
        /*num-1不存在 检查 存在的nums-1的话 跳过*/
        if(!num_set.count(i-1))
        {
            int count = 1;
            while(num_set.count(i+count))
            {
                currentStreak++;
                count++;
            }
            if(currentStreak>longestStreak)
                longestStreak=currentStreak;
            
        }
    }
    return longestStreak;
}
/*Solve2: 动态规划*/
int longestConsecutive2(vector<int>& nums) {
    unordered_map<int,int> num_map;
    int longestStreak=0;
    return longestStreak;
}
int main()
{
    vector<int> nums={1,4,3,2,7,8,9,10,5,6};
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}