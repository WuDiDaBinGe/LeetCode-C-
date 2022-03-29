#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct DoubleNode {
    DoubleNode *pre;
    DoubleNode *next;
    int key;
    int value;
    DoubleNode():key(-1),value(-1),pre(nullptr),next(nullptr){}
    DoubleNode(int key_,int value_):key(key_),value(value_),pre(nullptr),next(nullptr){}
};
class LRUCache {
private:
    DoubleNode *head;
    DoubleNode *tail;
    unordered_map<int, DoubleNode*> map_cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new DoubleNode();
        tail = new DoubleNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (map_cache.count(key)==0) 
            return -1;
        //获取key值 并将其移到链表头表示最近刚访问过
        moveToHead(map_cache[key]);
        return map_cache[key]->value;
    }
    
    void put(int key, int value) {
        DoubleNode* new_node = new DoubleNode(key, value);
        // key本来就存在
        if (map_cache.count(key)!=0){
            // delete old,add first to head
            deleteNode(map_cache[key]);
            map_cache[key] = new_node;
            addToHead(map_cache[key]);
            return;
        }
        // key不存在需要添加
        // capacity is full
        if (map_cache.size()==cap) {
            // fist: delete tail (oldest)
            // second: add node to head
            int del_key = deleteTail();
            map_cache.erase(del_key);
            addToHead(new_node);
            map_cache.insert(make_pair(key,new_node));
        } 
        else{
            // add to head
            addToHead(new_node);
            map_cache.insert(make_pair(key,new_node));
        }
    }
    // 把node插入头部
    int addToHead(DoubleNode* node) {
        node->next = head->next;
        node->pre = head;

        head->next->pre = node;
        head->next=node;
        return node->key;
    }
    // 删除节点
    int deleteNode(DoubleNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        return node->key;
    }
    // 将某个节点移到头部位置 1.先删除 2. 在从头部插入
    int moveToHead(DoubleNode* node){
        deleteNode(node);
        return addToHead(node);
    }
    // 删除双向链表的尾部元素
    int deleteTail(){
        return deleteNode(tail->pre);
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */