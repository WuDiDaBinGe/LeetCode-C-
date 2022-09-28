#include <iostream>
#include <stack>
using namespace std;
class CQueue {
public:
    stack<int> stk1, stk2;
    CQueue() {
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                int value = stk1.top(); stk1.pop();
                stk2.push(value);
            }
        }
        // 没有元素了
        if(stk2.empty()) return -1;
        int value  = stk2.top();
        stk2.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */