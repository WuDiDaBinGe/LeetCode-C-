#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int GetNumberOfK(vector<int> data, int k) {
        int n = data.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (k == data[mid]) {
                right--;
            } else if (data[mid] < k) {
                left++;
            } else {
                right--;
            }
        }
        int l1 = left;
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (k == data[mid]) {
                left++;
            } else if (data[mid] < k) {
                left++;
            } else {
                right--;
            }
        }
        return left - l1;
    }
};
int main(){
    return 0;
}