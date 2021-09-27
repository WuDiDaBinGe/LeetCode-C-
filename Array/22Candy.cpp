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
int main() {
    vector<int> t = {2,1};
    cout<<candy(t)<<endl;
    return 0;
}