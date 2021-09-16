#include<iostream>
#include<vector>
using namespace std;
void print_list(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
void print_list(vector<char>& nums){
    for (int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}