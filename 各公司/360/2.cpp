#include<bits/stdc++.h>
using namespace std;
void partition(vector<int>& nums, int l, int r, int flag) {
    int  cur = l;
    vector<int> small, bigger;
    int same = 0;
    for(int cur = 0; cur < nums.size();cur++) {
        if(nums[cur] < flag) {
            small.push_back(nums[cur]);
        }
        else if(nums[cur] == flag)
            same++;
        else if(nums[cur] > flag) {
            bigger.push_back(nums[cur]);
        }
    }
    cur = 0;
    for(int i = 0; i < small.size(); ++i) {
        nums[cur] = small[i];
        cur++;
    }
    for(int i = 0; i < same; ++i) {
        nums[cur] = flag;
        cur++;
    }
    for(int i = 0; i < bigger.size(); ++i) {
        nums[cur] = bigger[i];
        cur++;
    }
}
void print_list(vector<int> nums) {
    for(int i = 0; i < nums.size(); ++i) {
        cout<<nums[i];
        if(i == nums.size() - 1) 
            cout<<endl;
        else
            cout<<" ";
    }
}
int main()
{
   int n; cin>>n;
   vector<int> nums(n);
   for(int i = 0; i < n; ++i)
        cin>>nums[i];
   int t;cin>>t;
   vector<int> flags(t);
   for(int i = 0; i< t; ++i) {
        cin>>flags[i];
        partition(nums, 0, n - 1, flags[i]);
   }
   print_list(nums);
   return 0;
}