#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 解密
     * @param encryptedNumber int整型 待解密数字
     * @param decryption int整型 私钥参数D
     * @param number int整型 私钥参数N
     * @return int整型
     */
    int Decrypt(int encryptedNumber, int decryption, int number) {
        
    }

};
class Solution:
    def Decrypt(self , encryptedNumber: int, decryption: int, number: int) -> int:
        return pow(encryptedNumber, decryption) % number
int main(){
    cout<<pow(4296, 1601)<<endl;
    return 0;
}
