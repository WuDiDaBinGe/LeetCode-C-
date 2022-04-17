#include<iostream>
#include<algorithm>
#include<vector>
#include "utils.cpp"
using namespace std;

/*
    使用格雷编码的镜像排列
    不要考虑处理二进制字符串
*/
vector<int> grayCode2(int n) {
    vector<int> result;
    if (n==0) {
        result.push_back(0);
        return result;
    }
    result.push_back(0);
    result.push_back(1);
    if(n==1)
        return result;
    for (int i = 2; i <= n; i++) {
        int height_bit = 1<<(i-1);
        // 从后向前遍历
        for (int j = result.size()-1; j >=0; j--)
            // 利用位运算往前面加1
            result.push_back(result[j] | height_bit);
    }
    return result;
}
/*
    格雷编码的使用二进制转格雷码
    数学公式为： 整数n的格雷码为 n ⊕ (n/2)
*/
vector<int> grayCode(int n) {
    vector<int> res;
    const int size=1<<n; //2^n
    for (int i = 0; i < size; i++)
    {
        res.push_back(i^(i/2));
    }
    return res;
}
int main()
{
    print_list(grayCode(0));
    return 0;
}