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
            // aa a* or aa b*
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
                return isHelper2(index1 + 1, index2 + 1);
            } else {
                return false;
            }
        }
        else{
            // aa a* or aa b*
            if(ss[index1] == pp[index2] || (pp[index2] == '.' && index1 < ss.size())) {
                return isHelper2(index1, index2 + 2) 
                        || (index1 + 1, index2 + 2)
                        || (index1 + 1, index2);
            }
            return isHelper2(index1, index2 + 2);
        }
    }
};