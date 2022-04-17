#include<iostream>
#include<vector>
#include"utils.cpp"
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    // 进位表示
    int temp = 0;
    int n = digits.size();
    digits[n-1] += 1;
    temp = digits[n-1] / 10 ;
    if (temp == 0)
        return digits;
    digits[n-1] = digits[n-1] % 10;
    if (n>=2) {
        for (int i=n-2;i>=0;i--) {
            digits[i] += temp;
            temp = digits[i] / 10 ;
            if (temp == 0)
                return digits;
            digits[i] = digits[i] % 10;
        }
    }
    //最后还需要进位 需要往vector头部插入1
    if (temp == 1)
        digits.insert(digits.begin(),temp);
    return digits;
}
int main()
{
    vector<int> nums={4,3,2,1};
    print_list(plusOne(nums));
    return 0;
}