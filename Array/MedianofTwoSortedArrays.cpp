#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (int i = 0; i < nums.size(); i++)
        num_set.insert(nums[i]);
    long longestStreak =0;
    for (auto i:nums)
    {
        if(num_set.count(i)){
            
        }
        
    }
    

}
int main()
{
    
    return 0;
}