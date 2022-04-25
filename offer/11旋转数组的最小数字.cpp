#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int start = 0, end = n - 1;
        if(numbers[0] < numbers[n - 1]) return numbers[0];
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(end == start) {
                break;
            }
            if(numbers[mid] > numbers[end]) {
                start = mid + 1;
            }
            else if(numbers[mid] < numbers[end]) {
                end = mid;
            }
            else {
                end--;
            }
            //cout<<start<<" "<<end<<endl;
        }
        return numbers[start];
    }
};