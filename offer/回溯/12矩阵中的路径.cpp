#include <iostream>
#include <stack>
#include<vector>
using namespace std;
// 精简dfs
class Solution1 {
public:
    vector<vector<bool>> visited;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool hasPath(vector<vector<char> >& matrix, string word) {
        n = matrix.size(), m = matrix[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == word[0]) {
//                     visited = vector<vector<bool>>(n, vector<bool>(m, false));
                    if(dfs(i, j, 0, word, matrix)) return true;
                }
            }
        return false;
    }
    bool dfs(int row, int col, int index, string& word, vector<vector<char>>& matrix) {
        if(row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || matrix[row][col] != word[index]) return false;
        //valid
        if(index == word.size() - 1){
            return true;
        }
        //purne

        visited[row][col] = true;
        int res = false;
        for(int i = 0; i < 4; ++i) {
            int nx = row + dirs[i][0];
            int ny = col + dirs[i][1];
            res = res || dfs(nx, ny, index + 1, word, matrix);
        }
        visited[row][col] = false;
        return res;
    }
};
class Solution {
public:
    string path;
    vector<vector<bool>> visited;
    int n, m;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        path = "";
        n = board.size(); m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, word, board)) return true;
            }
        }
        return false;
    }
    bool dfs(int x, int y, int index, string word, vector<vector<char>>& map) {
        // border
        if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] != word[index] || visited[x][y] ) return false;
        path.push_back(map[x][y]);
        visited[x][y] = true;
        // valid
        if(index == word.size() - 1) {
            //cout<<path<<endl;
            return true;
        }
        //purne
        //get choice
        bool ret = false;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            ret = ret || dfs(nx, ny, index + 1, word, map);
        }
        visited[x][y] = false;
        path.pop_back();
        return ret;
    }
};
