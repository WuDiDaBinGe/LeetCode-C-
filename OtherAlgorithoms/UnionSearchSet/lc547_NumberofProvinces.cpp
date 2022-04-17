#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int P[202], Rank[202];
    //初始化并查集
    void init(int n) {
        // 每个元素相互独立
        for(int i = 0; i < n; i++) {
            P[i] = i;
            Rank[i] = 1;
        }
    }
    // 查找操作
    int find(int i) {
        return P[i] == i ? i : P[i] = find(P[i]);
    }
    // 合并操作
    void merge(int i, int j) {
        int x  = find(i), y = find(j);
        if(x == y) return;
        // 深度小的树 向 深度深的树合并
        if(Rank[x] <= Rank[y]) {    
            P[x] = y;
        }
        else{
            P[y] = x;
        }
        //如果深度相同且根节点不同，则新的根节点的深度+1
        if(Rank[x] == Rank[y] && x != y) 
            Rank[y]++;
        
    }
    // 并查集
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        init(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(isConnected[i][j] == 1)
                    merge(i, j);
            }
        }
        for(int i = 0; i < n; i++){
            cout<<P[i]<<" ";
            if(i == P[i])
                res++;
        }
        return res;
    }
};