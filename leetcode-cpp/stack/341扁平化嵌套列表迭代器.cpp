#include<bits/stdc++.h>
using namespace std;
// 迭代法
class NestedIterator {
    vector<int> data;
    int cur = 0;
    void dfs(vector<NestedInteger>& nestedList) {
        for(NestedInteger& ni:nestedList) {
            if(ni.isInteger())
                data.push_back(ni.getInteger());
            else
                dfs(ni.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int res = data[cur];
        cur++;
        return res;
    }
    
    bool hasNext() {
        return cur < data.size(); 
    }
};
// 使用栈
class NestedIterator {
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; --i) {
            stk.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = stk.top(); stk.pop();
        return res;
    }
    
    bool hasNext() {
        while(!stk.empty()) {
            NestedInteger cur = stk.top();
            if(cur.isInteger())
                return true;
            stk.pop();
            // 不是整数
            vector<NestedInteger> vecs = cur.getList();
            for(int i = vecs.size() - 1; i >= 0; --i) {
                stk.push(vector[i]);
            }
        }
    }
};
int main() {
    return 0;
}