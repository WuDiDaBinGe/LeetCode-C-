#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int result = -1;
    int size = gas.size();
    // 不同的起点
    for (size_t i = 0; i < size; i++) {
        //目前的油量
        int j = i;
        int sum = gas[i];
        // 从起点出发 比较sum 和 cost
        // 剩余大于消耗
        while (sum >= cost[j]) {
            sum = sum - cost[j];
            j = (j+1)%size;
            sum =sum+ gas[j];
            if (j == i) {
                return i;
            }
        }
    }
    return -1;
}
/*
    优化思路一：记录从i节点开始能到达的最远的节点j以及剩余的油量
    这样在遍历的时候直接跳到该节点能到达的最远的节点即可
*/
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    int result = -1;
    int size = gas.size();
    // 记录每个节点到达的最远地方 ()初始为0
    int* far_posi = new int[size]();
    fill_n(far_posi,size,-1);
    // 达到最远的节点剩余的油量
    int* far_remo_gas = new int[size]();
    // 不同的起点
    for (size_t i = 0; i < size; i++) {
        //目前的油量
        int sum = 0;
        int j = i;
        int p_size =0;
        // 从起点出发 比较sum 和 cost
        cout<<"Start Node:"<<i<<endl;
        do
        {
            sum += gas[j];
            if (cost[j] > sum) {
                // 记录信息
                far_posi[i]=j;
                far_remo_gas[i]=sum-gas[j];
                break;
            } 
            // 到达下一站
            sum =sum - cost[j];
            p_size ++;
            j = (j + 1) % size;
            if (far_posi[j]!=-1&&far_posi[j]!=j) {
                p_size += (far_posi[j]-j+size)%size;
                sum += far_remo_gas[j];
                // 该节点最远的位置
                j = far_posi[j];
            }
            cout<<"Next node:"<<j<<endl;
        } while (j != i);
        if (j==i && p_size==size)
            return i;
    }
    delete []far_posi;
    delete []far_remo_gas;
    return result;
}
/*
优化二：假设如果如果i最远能到达j，那么i~j中间的节点(包含j节点)是否能绕一圈呢？ 答：不能。
        证明： 假设i+1 节点能绕一圈那么i+1 一定能到达j+1，因为i->i+1 i+1->j+1 
        所以i可以到达j+1 已知i最远到达j，矛盾所以i+1 不能绕一圈。
        根据以上结论直接找到i到达的最远的节点j，下次循环直接从j节点考虑。
*/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    // 不同的起点
    for (size_t i = 0; i < size; i++) {
        //目前的油量
        int j = i;
        int sum = gas[i];
        // 从起点出发 比较sum 和 cost
        // 剩余大于消耗
        while (sum >= cost[j]) {
            sum = sum - cost[j];
            j = (j+1)%size;
            sum =sum+ gas[j];
            if (j == i) {
                return i;
            }
        }
        //最远距离在i之前 那么后面的不用检查了 直接退出
        if (j<i) 
            return -1;
        // 直接从j+1 开始看
        i = j;
    }
    return -1;
}
/*时间复杂度为O(N)的解法*/
// 不太理解。。。
/*
    total 确定总的是够满足
    如果总的满足 那么确定每一段之间是否满足，接着上一种方法理解
    i最远到j 那么i-j之间的节点都不能作为起点
    即要选择j后面的点作为起点
*/
int canCompleteCircuitON(vector<int>& gas, vector<int>& cost) {
    int j =0;
    int total =0;
    for (int i = 0, sum=0; i < gas.size(); i++) {
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (sum < 0) {
            sum = 0;
            j =i ;
        }
    }
    return total<=0?-1:j+1;
    
}
int main() {
    vector<int> gas = {5,1,2,3,4};
    vector<int> cost = {4,4,1,5,1};
    cout<<canCompleteCircuitON(gas, cost);
    return 0;
}