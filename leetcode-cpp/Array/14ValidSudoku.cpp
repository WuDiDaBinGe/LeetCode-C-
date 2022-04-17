#include<iostream>
#include<vector>
#include<algorithm>
#include "utils.cpp"
using namespace std;
/*传入一个数组检查是否为1-9 没有重复*/
bool check(vector<char> nums){
    vector<bool> used = {false,false,false,false,false,false,false,false,false}; 
    for(int i=0;i<nums.size();i++){
        if(nums[i]!='.'){
            if(used[int(nums[i]-'1')] == true){
                return false;
            }
            else{
                used[int(nums[i]-'1')] = true;
            }
        }     
    }
    return true;
}
bool check(char num,bool used[9]){
    if(num=='.') return true;
    if(used[num-'1']==true) return false;
    return used[num-'1']=true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    /*检查行*/
    for (int i = 0; i < board.size(); i++)
    {
        print_list(board[i]);
        if(check(board[i]))
            continue;
        else
            return false;
    }
    /*检查列*/
    for (int i = 0; i < board.size(); i++)
    {
        /*取出一列*/
        vector<char> col;
        for (int row = 0; row < board.size(); row++)
            col.push_back(board[row][i]);
        
        if(check(col))
            continue;
        else
            return false;
    }
    /*检查3*3的矩阵*/
    for(int i=0;i<board.size()-1;i=i+3)
    {
        for (int j = 0; j < board.size()-1; j=j+3)
        {
            vector<char> nums;
            for (int margin = 0; margin <3; margin++)
                for (int m_col = 0; m_col < 3; m_col++)
                    nums.push_back(board[i+margin][j+m_col]);
            
            if(check(nums))
                continue;
            else
                return false;
        }
    }
    return true;
}
bool isValidSudoku_book(vector<vector<char>>& board) {
    bool  used[9];
    // 检查行
    for(int i=0;i<9;i++)
    {
        fill(used,used+9,false);
        for(int j=0;j<9;j++)
        {
            if(check(board[i][j],used)==false)
                return false;
        }
    }
    //检查列
    for(int i=0;i<9;i++)
    {
        fill(used,used+9,false);
        for(int j=0;j<9;j++)
        {
            if(check(board[j][i],used)==false)
                return false;
        }
    }
    /*检查3*3的矩阵*/
    for(int i=0;i<board.size()-1;i=i+3)
    {
        for (int j = 0; j < board.size()-1; j=j+3)
        {
            fill(used,used+9,false);
            for (int margin = 0; margin <3; margin++)
            {
                for (int m_col = 0; m_col < 3; m_col++)
                {
                    if(check(board[i+margin][j+m_col],used)==false)
                        return false;
                }
            }       
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> board = 
    {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    cout<<isValidSudoku_book(board)<<endl;
    return 0;
}