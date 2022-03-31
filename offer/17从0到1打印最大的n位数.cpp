#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<unordered_map>
using namespace std;
// 没有考虑大数的做法
vector<int> printNumbers(int n) {
    vector<int> res;
    int end = pow(10, n) - 1;
    for(int i = 1; i <= end; i++)
        res.push_back(i);
    return res;
}
// 考虑大数的做法
// 1. 使用字符串模拟
// 2. 使用递归全排列

// 2.使用递归解决
void dfs(int index, int length, string path, vector<int>& res) {
    if(index == length) {
        int i;
        for(i = 0; i < path.size(); i++) {
            if(path[i] != '0')
                break;
        }
        if(i < path.size()) {
            res.push_back(stoi(path.substr(i)));
            cout<<res[res.size() - 1]<<endl;
        }
        return;
    }
    for(int i = 0; i <= 9; i++) {
        path[index] = '0' + i;
        dfs(index + 1, length, path, res);
    }
}
vector<int> printNumbers2(int n) { 
    vector<int> res;
    string path(n, '0');
    dfs(0, n, path, res);
    return res;
}

int main(){
    printNumbers2(2);
    return 0;
}