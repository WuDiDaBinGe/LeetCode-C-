#include<bits/stdc++.h>
using namespace std;
// 维护一个单调的双端队列
class MaxQueue {
public:
    queue<int> data;
    deque<int> help;
    MaxQueue() {
    }
    
    int max_value() {
        if(!help.empty()) return help.front();
        else return -1;
    }
    
    void push_back(int value) {
        data.push(value);
        while(!help.empty() && help[help.size() - 1] < value) help.pop_back();
        help.push_back(value);
    }
    
    int pop_front() {
        int t = -1;
        if(!data.empty()) {
            t = data.front();
            if(t == help.front()) help.pop_front();
            data.pop();
        }
        return t;
    }
};
int main() {
    return 0;
}