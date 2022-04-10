#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> data;
    int mid = -1;
    MedianFinder() {

    }
    //
    void addNum(int num) {
        if(mid == -1) {
            data.push_back(num);
            mid = 0; 
            return;
        }
        // 二分
        int left = 0, right = 0;
        if(data[mid] >= num) {
            left = 0;
            right = mid;
        } else {
            left = mid;
            right = data.size() - 1;
        }
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(data[mid] <= num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        data.insert(data.begin() + left, num);
        mid = (data.size() - 1) / 2;
    }
    double findMedian() {
        if(mid == -1) return 0.0;
        if(data.size() % 2 == 0) {
            return (data[mid] + data[mid + 1] + 0.0) / 2;
        } else {
            return data[mid];
        }
    }
};

class MedianFinder1 {
public:
    /** 使用两个堆来实现中位数 **/
    priority_queue<int> smallBigHeap;
    priority_queue<int, vector<int>, greater<int>> bigSmallHeap;
    MedianFinder1() {

    }
    void addNum(int num) {
        // m == n  add a samll num in bigSmallHeap to smallBigHeap
        if(smallBigHeap.size() == bigSmallHeap.size()) {
            bigSmallHeap.push(num);
            smallBigHeap.push(bigSmallHeap.top());
            bigSmallHeap.pop();
        } 
        // m != n add a bigger num in smallBigHeap to bigSmallHeap
        else {
            smallBigHeap.push(num);
            bigSmallHeap.push(smallBigHeap.top());
            smallBigHeap.pop();
        }
    }
    double findMedian() {
        if(smallBigHeap.size() == bigSmallHeap.size()) {
            return (smallBigHeap.top() + bigSmallHeap.top() + 0.0) / 2;
        } else {
            return smallBigHeap.top();
        }
    }
};
int main() {
    MedianFinder1* obj = new MedianFinder1();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(2);
    obj->addNum(3);
    obj->addNum(3);
    cout<<obj->findMedian()<<endl;
    return 0;
}