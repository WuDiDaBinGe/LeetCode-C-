#include<iostream>
#include<vector>
using namespace std;
/*
    对于每一根柱子，其上盛放雨水的面积为：min(左边最高，右边最高) - height
    所以：
    1. 从左往右遍历 找到每一根柱子左边的最高
    2. 从右往左遍历 找到每一根柱子右边的最高
    3. 计算每一根柱子的可以盛放雨水的面积求和
*/
int trap(vector<int>& height) {
    int size = height.size();
    int *left_max = new int[size]();
    int *right_max = new int[size]();
    int res =0;
    //从左向右遍历
    for(int i=1;i<size;i++)
    {
        left_max[i] = max(left_max[i-1],height[i-1]);
        right_max[size-i-1] = max(right_max[size-i],height[size-i]);
    }
    for (int i = 0; i < size; i++)
    {
        int height_max = min(left_max[i],right_max[i]);
        if(height_max > height[i])
        {
            res += height_max - height[i];
        }
    }
    delete left_max;
    delete right_max;
    return res;
    
}
/*
    找到最高的柱子，处理左边和右边的值
    1. 从左边到最高 (每一个柱子能接水的面积为:max(该柱子左边所有柱子的最高)-该柱子的高度)
    2. 从右边到最高 (每一个柱子能接水的面积为:max(该柱子右边所有柱子的最高)-该柱子的高度)
*/
int trap2(vector<int>& height){
    int max_index =0;
    for (int i = 0; i < height.size(); i++)
    {
        if(height[i]>height[max_index])
            max_index =i;
    }
    int water=0;
    //左边 左边柱子的右边一定有最高的柱子，只要找到其左边最高的柱子即可
    for (int i = 0, peak =0 ; i < max_index; i++)
    {
        if(height[i]>peak) peak = height[i];
        else water += peak-height[i];
    }
    //右边
    for (int i = height.size()-1,peak=0; i >= max_index; i--)
    {
        if (height[i]>peak) peak = height[i];
        else water += peak-height[i];
    }
    return water;
}
/*
    使用辅助栈的方法
    
*/
int trap3(vector<int>& height){
    
}
int main()
{
    vector<int> a ={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap2(a)<<endl;
    return 0;
}