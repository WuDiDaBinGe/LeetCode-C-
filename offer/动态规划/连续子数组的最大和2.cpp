#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        int n = array.size();
        if (n == 1) return array;
        int left = 0, right = 0;
        int sum = array[0];
        int res = sum;
        int l1 = 0, l2 = 0;
        for (int i = 2; i <= n; ++i) {
            if ((sum + array[i - 1]) >= array[i - 1]) {
                sum = sum + array[i - 1];
                right = i - 1;
            } else {
                sum = array[i - 1];
                left = i - 1;
                right = i - 1;
            }
            if(sum > res || (sum == res && (right - left) > (l2 - l1))) {
                res = sum;
                l1 = left;
                l2 = right;
            }
        }
        vector<int> res1;
        for (int i = l1; i <= l2; ++i) {
            res1.push_back(array[i]);
        }
        return res1;
    }
};