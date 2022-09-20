#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string ss, pp;
    bool isMatch(string s, string p) {
        ss = s; pp = p;
        return isHelper(0 , 0);
    }
    bool isHelper(int index1, int index2) {
        if(index2 == pp.size()) return index1 == ss.size();
        char c = index2 + 1 < pp.size()? pp[index2 + 1]: '0'; 
        if(c != '*') {
            if(ss[index1] == pp[index2] || (pp[index2] == '.' && index1 < ss.size())) {
                return isHelper(index1 + 1, index2 + 1);
            } else {
                return false;
            }
        }
        else{
            // 看懂这里
            // aa a* or aa b*
            // 这里可以理解为从哪里进行模式串的下一步匹配
            while(ss[index1] == pp[index2] || (pp[index2] == '.' && index1 < ss.size())) {
                if(isHelper(index1, index2 + 2))
                    return true;
                index1++;
            }
            return isHelper(index1, index2 + 2);
        }
    }
    bool isHelper2(int index1, int index2) {
        if(index2 == pp.size()) return index1 == ss.size();
        char c = index2 + 1 < pp.size()? pp[index2 + 1]: '0'; 
        if(c != '*') {
            if(ss[index1] == pp[index2] || (pp[index2] == '.' && index1 < ss.size())) {
                return isHelper(index1 + 1, index2 + 1);
            } else {
                return false;
            }
        }
        else{
            // aa a* or aa b*
            if(ss[index1] == pp[index2] || (pp[index2] == '.' && index1 < ss.size())) {
                
                return isHelper(index1, index2 + 2)     // 匹配模式串本次不匹配，
                        || isHelper(index1 + 1, index2 + 2) //模式串本次匹配一个字符
                        || isHelper(index1 + 1, index2);    // 模式串本次匹配的字符还没完
            }
            return isHelper(index1, index2 + 2);
        }
    }
};