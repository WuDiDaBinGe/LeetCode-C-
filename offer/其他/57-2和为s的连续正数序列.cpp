#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> result;
    // 枚举首项
    for(int a = 1; a < target; ++a) {
        // 枚举个数
        int n = a, sum = a;
        vector<int> res;
        while(sum <= target) {
            res.push_back(n);
            if(sum == target) {
                result.push_back(res);
                break;
            }
            n++;
            sum += n;
        }
    }
    return result;
}
// 滑动窗口
vector<vector<int>> findContinuousSequence(int target) {
    int left = 1, right = 1;
    int sum = 0;
    vector<vector<int>> result;
    vector<int> window;
    while(right < target) {
        sum += right;
        window.push_back(right);
        right++;
        while (sum >= target) {
            if(sum == target){
                result.push_back(window);
            }
            window.erase(window.begin());
            sum -= left;
            left++;
        }
        
    }
    return result;
}
// 滑动窗口
class Solution {
  public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int left = 1;
        int cur = 1;
        int _sum = 0;
        vector<vector<int>> res;
        if (sum == 0 || sum == 1) return res;
        while (cur <= (sum / 2 + 1) ) {
            _sum += cur;
            cur++;
            while (_sum > sum) {
                _sum -= left;
                left++;
            }
            if (_sum == sum ) {
                vector<int> t;
                for (int i = left; i < cur; ++i) {
                    t.push_back(i);
                }
                res.push_back(t);
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}