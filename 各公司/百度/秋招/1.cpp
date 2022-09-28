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
    vector<int> nums(N);
    vector<pair<int, int>> input_ops(M);
    for(int i = 0; i < N; ++i)
        cin>>nums[i];
    for(int i = 0; i < M; ++i){
        int op, k; cin>>op>>k;
        input_ops[i].first = op;
        input_ops[i].second = k;
    }
    vector<pair<int, int>> valid_ops;
    valid_ops.push_back({0, 0});
    int x = 0;
    // 后一个排序的K值大于前面的K值没必要再进行排序了
    for(int i = M - 1; i >= 0; --i){
        if(input_ops[i].second > x) {
            valid_ops.push_back(input_ops[i]);
            x = input_ops[i].second;
        }
    }
    vector<int> data = nums;
    sort(data.begin(), data.begin() + valid_ops.back().second);
    int l = 0, r = valid_ops.back().second - 1;
    int index = r;
    for(int i = valid_ops.size() - 1; i > 0; --i) {
        int k = valid_ops[i].second - valid_ops[i - 1].second;
        // 从小到大
        if(valid_ops[i].first == 1) {
            // 找最大的数
            for(int j = 0; j < k; ++j){
                nums[index] = data[r];
                r--;
                index--;
            }
        }
        // 从大到小
        if(valid_ops[i].first == 2) {
            // 找最小的数
            for(int j = 0; j < k; ++j){
                nums[index] = data[l];
                l++;
                index--;
            }
            
        }
        
    }
    for(int y = 0; y < nums.size(); ++y)
        cout<<nums[y]<<" ";
    return 0;
}
