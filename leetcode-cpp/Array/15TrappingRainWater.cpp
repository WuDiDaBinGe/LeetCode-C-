#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*从左向右遍历，遍历找到不低于第i个柱子j，中间肯定可以
    防水,雨水面积为两者之间长方形-中间柱子的面积。
*/
int trap(vector<int>& height) 
{
    int i=0;
    int area = 0;
    int length = height.size();
    while (i<length-2)
    {
        if (height[i] == 0){
            i++;
            continue;
        }
        // 从隔一个的柱子开始找
        int j = i+1;
        int max_value = -1;
        int max_index = j;
        while (j<length && height[j]<height[i])
        {
            if(height[j]>=max_value)
            {
                max_value = height[j];
                max_index = j;
            }
            j++;
        }
        cout<<i<<"  "<<j<<" "<<endl;
        // 到最后没找到比他高的 需要找到剩下的最高的
        int temp_area = 0;
        if (j>=length)
        {
            int width = max_index-i-1;
            if(width ==0){
                i++;
                continue;
            }
            int height_ = max_value;
            int sub_area = 0;
            for (int t = i+1; t < max_index; t++)
            {
                sub_area += max_value<height[t]?max_value:height[t];
            }
            temp_area =(width*height_)-sub_area;
            i = max_index;
        }
        // 找到比i他高的了
        else{
            int width = j-i-1;
            if(width ==0){
                i++;
                continue;
            }
            int height_ = height[i];
            int sub_area = 0;
            for(int t=i+1;t<j;t++){
                sub_area += height[t]>height[i]?height[i]:height[t];
            }
            temp_area =(width*height_)-sub_area;
            i = j;
        }
        cout<<" Add area:"<<temp_area<<endl;
        area += temp_area;
    }
    return area;
}
int main(){
    vector<int> height = {9,6,8,8,5,6,3};
    cout<<trap(height)<<endl;
    return 0;
}