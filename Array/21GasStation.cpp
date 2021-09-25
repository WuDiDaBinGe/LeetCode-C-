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
        int sum = 0;
        int j = i;
        int p_size =0;
        cout<<"start："<<j<<endl;
        // 从起点出发 比较sum 和 cost
        do
        {
            sum += gas[j];
            if (cost[j] > sum) 
                break;
            // 到达下一站
            sum =sum - cost[j];
            p_size ++;
            cout<<sum<<endl;
            j = (j + 1) % size;
        } while (j != i);
        if (j==i && p_size==size)
            return i;
    }
    return result;
    
}
int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<canCompleteCircuit(gas, cost);
    return 0;
}