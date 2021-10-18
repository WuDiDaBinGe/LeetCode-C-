#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    // int1: time int2:key
    vector<pair<int,int>> cache;
    unordered_map<int, int> umap;
    int count = 0;
    int max_count = 0;
    LRUCache(int capacity) {
        max_count = capacity;
        for (int i=0;i<capacity;i++) {
            cache.push_back(make_pair(-1,-1));
        }
    }
    
    int get(int key) {
        bool flag=false;
        for(int i=0;i<cache.size();i++){
            if (cache[i].second==key){
                cache[i].first=0;
                flag=true;
            }
            else if (cache[i].second!=-1&&cache[i].second!=key) 
                cache[i].first++;
        }
        if (!flag) 
            return -1;
        else {
            // 更新时间t标值
            return umap[key];
        }
    }
    
    void put(int key, int value) {
        // 更新原来的key
        if(umap.find(key)!=umap.end()) {
            // 更新原来的key值
            umap[key] = value;
            // 更新数组标志链表
            for (int i=0;i<max_count;i++) {
                if (cache[i].second==key) {
                    cache[i].first =0;
                }
                else if (cache[i].second != -1) {
                    cache[i].first++;
                }
            }
            return;
        }
        // 需要置换页面
        if (count>=max_count) {
            // find the oldest node to replace
            int oldest=-1,old_index=-1;
            for (int i=0;i<max_count; i++) {
                if (cache[i].first>oldest) {
                    oldest = cache[i].first;
                    old_index = i;
                }
            }
            // 删除原来的key-value pair
            umap.erase(cache[old_index].second);
            for (int i=0;i<max_count; i++) {
                if (i==old_index){
                    cache[i].second = key;
                    umap.insert(make_pair(key,value));
                    cache[i].first = 0;
                }
                else {
                    cache[i].first++;
                }
            }
        }
        // 无需置换页面
        else {
            for (int i = 0; i < max_count; i++) {
                // find empty node
                if (cache[i].second == -1){
                    cache[i].second = key;
                    umap.insert(make_pair(key,value));
                    cache[i].first = 0;
                    count++;
                    break;
                }
                else{
                    cache[i].first++;
                }
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
    双向链表+unorder_map
*/
struct DoubleNode {
    DoubleNode *pre;
    DoubleNode *next;
    int key;
    int value;
    DoubleNode():key(-1),value(-1),pre(nullptr),next(nullptr){}
    DoubleNode(int key_,int value_):key(key_),value(value_),pre(nullptr),next(nullptr){}
};
class LRUCacheR {
private:
    DoubleNode *head;
    DoubleNode *tail;
    unordered_map<int, DoubleNode*> map_cache;
    int cap;
public:
    LRUCacheR(int capacity) {
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
        // key本来就存在
        if (map_cache.count(key)!=0){
            // delete old,add first to head
            map_cache[key]->value = value;
            moveToHead(map_cache[key]);
            return;
        }
        // key不存在需要添加
        // capacity is full
        DoubleNode* new_node = new DoubleNode(key, value);
        if (map_cache.size()==cap) {
            // fist: delete tail (oldest)
            // second: add node to head
            DoubleNode*  del_node = deleteTail();
            map_cache.erase(del_node->key);
            delete(del_node);
            addToHead(new_node);
            map_cache.insert(make_pair(key,new_node));
        } 
        else{
            // add to head
            addToHead(new_node);
            map_cache.insert(make_pair(key,new_node));
        }
    }

    int addToHead(DoubleNode* node) {
        node->next = head->next;
        node->pre = head;

        head->next->pre = node;
        head->next=node;
        return node->key;
    }
    // 给其他的操作函数使用 只是把链接断开 并没有删除内存
    int deleteNode(DoubleNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        return node->key;
    }
    int moveToHead(DoubleNode* node){
        deleteNode(node);
        return addToHead(node);
    }
    DoubleNode* deleteTail(){
        DoubleNode* temp = tail->pre;
        deleteNode(temp);
        return temp;
    }
    
};