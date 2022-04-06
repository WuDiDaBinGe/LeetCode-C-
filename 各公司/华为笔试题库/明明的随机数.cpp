#include<iostream>
#include<vector>
using namespace std;
int NUMS[510];
int main() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        int nums;cin>>nums;
        NUMS[nums] = 1;
    }
    for(int i = 1; i <= 500; i++) {
        if(NUMS[i] >= 1)
            cout<<i<<endl;
    }
    return 0;
}