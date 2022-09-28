#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    /** 使用一个辅助栈记录目前的栈的最小值 */
    stack<int> data, helper;
    MinStack() {
        //先放入一个很大的元素 防止 push的时候报错
        helper.push(INT_MAX);
    }
    
    void push(int x) {
        data.push(x);
        int cmin = helper.top();
        if(x < cmin) helper.push(x);
        else helper.push(cmin);
    }
    
    void pop() {
        if(data.empty()) return ;
        data.pop();
        helper.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */