#include<bits/stdc++.h>
using namespace std;
// 给出原点坐标 和 终点坐标
// 只能进行*2 或者 加1 操作 使得操作次数最少 达到目标坐标
long long GetMinCalculateCount(long long rx, long long ry, long long tx, long long ty) {
    long long cnt = 0;
    queue<pair<long long , long long >> q;
    q.push({rx, ry});

    while(!q.empty()){
        int len = q.size();
        while(len --){
            pair<long long, long long> p = q.front(); q.pop();
            long long x = p.first, y = p.second;

            if(x == tx && y == ty) return cnt;

            if(x+1 <= tx && y+1 <= ty) q.push({x+1, y+1});
            if(2*x <= tx && 2*y <= ty) q.push({2*x, 2*y});
        }
        cnt ++ ;
    }
    return -1;
}
int main() {
    cout<<GetMinCalculateCount(10,100,22,202)<<endl;
    cout<<GetMinCalculateCount(1,2,4,6);
    return 0;
}