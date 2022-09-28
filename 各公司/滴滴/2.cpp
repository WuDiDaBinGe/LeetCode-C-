#include<bits/stdc++.h>
using namespace std;
// 预处理 + 加前缀和
int memsets[700001];
int prefix[700001][16];
int getValue(int value){
    if(memsets[value] != -1) return memsets[value];
    int res = 0;
    while (value) {
        res ^= (value % 10);
        value = value / 10;
    }
    memsets[value] = res;
    return res;
}
void init() {
    for(int i = 0; i <= 70001; ++i) {
        prefix[i][getValue(i)] = 1;
    }
    // 前缀和 离线查询prefix数组
    for(int i = 0; i < 16; ++i) {
        for(int j = 0; j <= 70001; ++j) {
            if(j == 0) {
                continue;
            }
            prefix[j][i] += prefix[j - 1][i];
        }
    }
}

int main(){
    int T;cin>>T;
    vector<int> lefts(T), rights(T), values(T);

    for(int i = 0; i < T; ++i)
        cin>>lefts[i];
    for(int i = 0; i < T; ++i)
        cin>>rights[i];
    for(int i = 0; i < T; ++i)
        cin>>values[i];
    for (int t = 0; t < T; ++t) {
        int L=lefts[t], R=rights[t], V = values[t];
        int res = 0;
        for(int j = L; j <= R; ++j) {
            if(getValue(j) == V)
                res++;
        }
        cout<<res;
    }
    
    return 0;
}