#include<iostream>
#include<vector>
#include "utils.cpp"
using namespace std;
// 将图片顺时针旋转90度
/*
    思路：1.将矩阵按照副对角线元素进行交换
    2.再按照水平对称线进行交换

    矩阵关于副对角线翻着的规律：A[i][j] : A[size-1-j][size-1-i]
*/
void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size-i; j++)
            swap(matrix[i][j],matrix[size-1-j][size-1-i]);
    
    for (int i = 0; i < size / 2; i++)
        for (int j = 0; j < size; j++)
            swap(matrix[i][j],matrix[size-1-i][j]);
}
int main()
{
    vector<vector<int>> test = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    return 0;
}