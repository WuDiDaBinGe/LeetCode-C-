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
        // 需要置换页面
        if (count==max_count) {
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
                }
                else if (cache[i].second!=-1){
                    cache[i].first++;
                }
            }
        }

    }
};