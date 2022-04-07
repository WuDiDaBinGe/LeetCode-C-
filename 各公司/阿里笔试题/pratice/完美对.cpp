#include<bits/stdc++.h>
using namespace std;
int vec[100010][11];
int main() {
    int  n, k;
    cin>>n>>k;
    map<vector<int>, int> hashs;
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        vector<int> seq, seq_neg;
        for(int j = 0; j < k; ++j) {
            cin>>vec[i][j];
            if(j > 0) {
                // 本身的模式
                seq.push_back(vec[i][j] - vec[i][j - 1]);
                // 需要匹配的模式
                seq_neg.push_back(vec[i][j - 1] - vec[i][j]);
            }
        }
        res += hashs[seq_neg];
        hashs[seq]++;

    }
    cout<<res<<endl;
    return 0;
}