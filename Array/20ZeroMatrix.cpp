#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    bool cols[n]={false};
    bool rows[n]={false};
    for (int i=0;i<n;i++) 
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0) {
                cols[j]=true;
                rows[i]=true;
            }
    for (int i = 0; i < n; i++)
    {
        if (rows[i]==true) {
            for (int j=0;j<n;j++)
                matrix[i][j]=0;
        }
        if (cols[i] == true) {
            for (int j=0;j<n;j++)
                matrix[j][i]=0;
        }
    }
}

int main() {
    vector<vector<int>> a = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(a);
    return 0;
}