#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*自己的思路*/
int candy(vector<int>& ratings) {
    int size = ratings.size();
    int res =0;
    if (size==1) 
        return 1; 
    vector<int> gap_index;      //记录递减子序列中每个子序列中的最后一个元素
    for (int i = 0; i < size-1; i++) {
        // 递减序列
        if (ratings[i]>ratings[i+1])
            continue;
        else {
            // 出现不递减或者相等
            gap_index.push_back(i);
        }
    }
    
    if ( gap_index.size()==0 || gap_index.back() != size-1 ) {
        gap_index.push_back(size-1);
    }
    
    int result[size]; 
    // 分配糖果 初始分配 按照递减子序列分配len(子序列)，len(子序列)-1，...,1分配
    int candy=1;
    // int 不能直接向size_t 赋值
    for (int j = gap_index[0]; j >=0 ; j--) {
        result[j]=candy;
        candy++;
    }
    if (gap_index.size()==1) {
        for (int i = 0; i < size; i++) {
            cout<<result[i]<<" ";
            res += result[i];
        }
        return res;
    }
    for (int i = 1; i < gap_index.size(); i++) {
        int now_tail =gap_index[i];
        int last_tail = gap_index[i-1];
        int candy = 1;
        int j;
        for (j = now_tail; j >last_tail; j--) {
            result[j] = candy;
            candy++;
        }
        // 修正
        if (ratings[last_tail]<ratings[last_tail+1]) 
            result[last_tail+1]= max(result[last_tail]+1,result[last_tail+1]);
    }
    // 返回结果
    
    for (int i = 0; i < size; i++) {
        cout<<result[i]<<" ";
        res += result[i];
    }
    cout<<endl;
    return res;
}
/*
    贪心的四步：
    1. 分解子问题
    2. 找到合适的贪心策略
    3. 求解子问题，找到局部最优解
    4. 将局部最优解堆叠找到全局最优解
    将相邻孩子中评分最高的获得的糖果最多，化成两个规则
    1. 从左向右 如果右边的孩子评分比左边的高 那么candy[i]=candy[i]+1（因为最少-> +1贪心）
    2. 从右向左 如果左边孩子评分比右边孩子高 那么candy[i-1]=candy[i]+1
    两个子问题都达到了全局最优，如何得到全局最优？
    要求比邻居评分高的孩子即要大于左边孩子又要大于右边的孩子
    即对两个子问题求解max(left,right)
 */
int candy2(vector<int>& ratings) {
    int size = ratings.size();
    vector<int> candyvec(size,1);
    
    // 从前向后
    for (int i = 1; i < size; i++) {
        if (ratings[i]>ratings[i-1]) {
            candyvec[i]=candyvec[i-1]+1;
        }  
    }
    // 从后向前
    for (int i=size-2;i>=0;i--) {
        if (ratings[i]>ratings[i+1]) {
            candyvec[i]=max(candyvec[i+1]+1,candyvec[i]); 
        } 
    }
    int res=0;
    for (int i = 0; i < size; i++) {
        res += candyvec[i];
    }
    return res;
}
int main() {
    vector<int> t = {2,1};
    cout<<candy2(t)<<endl;
    return 0;
}