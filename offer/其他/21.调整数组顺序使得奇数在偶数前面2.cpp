#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
/*
    对奇数偶数之间的相对位置要求不变
*/
class Solution {
public:
    /*
        双指针：无需额外空间 移动数组元素
    */
    vector<int> reOrderArray(vector<int>& array) {
        int n = array.size();
        int l = -1, cur = 0;
        while(cur < n) {
            if(array[cur] % 2 == 0) {
                cur++;
                continue;
            }
            // 奇数
            // 移动
            int num = array[cur];
            for(int i = cur; i >  1 + l; --i) {
                array[i] = array[i - 1];
            }
            array[l + 1] = num;
            l++;
            cur++;
        }
        return array;
    }
};
class Solution1 {
public:
    vector<int> reOrderArray(vector<int>& array) {
        int n = array.size();
        vector<int> ji, ou;
        for(int num:array) {
            if(num % 2) ji.push_back(num);
            else ou.push_back(num);
        }
        vector<int> res;
        for(int num:ji) {
            res.push_back(num);
        }
        for(int num:ou) {
            res.push_back(num);
        }
        return res;
    }
};