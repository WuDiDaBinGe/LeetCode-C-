#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// if c in a-z||A-Z||0-9
bool isNC(char c){
    if(('a'<=c&&c<='z')||(c>='0'&&c<='9')||('A'<=c&&c<='Z')) {
        return true;
    }
    else
        return false;
}
bool isPalindrome(string s) {
    if(s.length()==0) return true;
    // tolower 
    transform(s.begin(), s.end(),s.begin(),::tolower);
    int left=0,right=s.length()-1;
    while (left<=right) {
        if (!isNC(s[left])) left++;
        else if (!isNC(s[right])) right--;
        else if (s[left]!=s[right]) return false;
        else {left++;right--;}
    }
    return true;
}
int main(){
    string test = "0P";
    cout<<isPalindrome(test)<<endl;
}