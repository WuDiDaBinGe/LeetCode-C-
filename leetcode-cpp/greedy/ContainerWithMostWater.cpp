#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxValue = INT8_MIN;
        while(left < right) {
            int heiV = min(height[left], height[right]);
            maxValue = max((right - left) * heiV, maxValue);
            if(height[left] <= height[right]) {
                left++;
            }else {
                right--;
            }
        }
        return maxValue;
    }
    
};
int main() {
    Solution s;
    vector<int> height = {1,3,2,5,25,24,5};
    cout<<s.maxArea(height)<<endl;
    return 0;
}