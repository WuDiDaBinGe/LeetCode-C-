/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> intervals) {
    int n = intervals.size();
    vector<vector<int>> res;
    if(n == 0) return res;
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i < n; ++i) {
        int L = intervals[i][0], R = intervals[i][1];
        // 没有重叠
        if(res.empty() || L > res.back()[1]) {
            res.push_back({L, R});
        } else {
            // 有重叠
            res.back()[1] = max(res.back()[1], R);
        }
    } 
    return res;
}
int main(){
    vector<vector<int>> intervals = {
        {1,3},{2,6},{8,10},{15,18}
    };
    vector<vector<int>> intervals1 = {
        {1,4},{4,5}
    };
    vector<vector<int>> intervals2 = {
        {8,10},{1,3},{2,6},{15,18}
    };
    vector<vector<int>> intervals3 = {
        {1,3},{4,6},{8,10},{-1,18}
    };
    // vector<vector<int>> result = merge(intervals);
    // vector<vector<int>> result1 = merge(intervals1);
    // vector<vector<int>> result2 = merge(intervals2);
    vector<vector<int>> result3 = merge(intervals3);
    int n;
    // for(int i = 0; i < n; ++i) {
    //     cout<<"["<<result[i][0]<<","<<result[i][1]<<"]"<<endl;
    // }
    // cout<<"***************"<<endl;
    // n = result1.size();
    // for(int i = 0; i < n; ++i) {
    //     cout<<"["<<result1[i][0]<<","<<result1[i][1]<<"]"<<endl;
    // }
    // cout<<"***************"<<endl;
    // n = result2.size();
    // for(int i = 0; i < n; ++i) {
    //     cout<<"["<<result2[i][0]<<","<<result2[i][1]<<"]"<<endl;
    // }
    // cout<<"***************"<<endl;
    n = result3.size();
    for(int i = 0; i < n; ++i) {
        cout<<"["<<result3[i][0]<<","<<result3[i][1]<<"]"<<endl;
    }
    return 0;
}
