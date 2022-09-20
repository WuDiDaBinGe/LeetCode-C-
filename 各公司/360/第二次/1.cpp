#include<bits/stdc++.h>
using namespace std;
/*
给定一个长度为N的序列A1到AN，
现在要对序列进行M次操作，每次操作对
序列的前若干项进行升序或降序排列，求经过这M次操作后得到的序列。
*/
bool comare(int a, int b){
    return a > b;
}
int main(){
    int N,M; cin>>N>>M;
    vector<long long> nums(N);
    pair<int, int> qujian1, qujian2;
    qujian1 = {0, 0};
    qujian2 = {0, 0};
    for(int i = 0; i < N; ++i)
        cin>>nums[i];
    while(M) {
        int op, end;
        cin>>op>>end;
        if(op == 0) {
            sort(nums.begin(), nums.begin() + end);
        }
        else if(op == 1) {
            sort(nums.begin(), nums.begin() + end, comare);
        } 
        M--;
    }
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    return 0;
}
