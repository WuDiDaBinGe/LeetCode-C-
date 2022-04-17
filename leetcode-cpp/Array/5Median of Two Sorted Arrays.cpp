#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> tmp;
    int m_index = (m + n)/2;
    int i=0,j=0;
    while (i<m&&j<n)
    {
        if(nums1[i]<=nums2[j])
        {
            tmp.push_back(nums1[i]);
            i++;
        }
        else
        {
            tmp.push_back(nums2[j]);
            j++;
        }
    }
    for (int ii = i; ii < m; ii++)
        tmp.push_back(nums1[ii]);
    for (int jj = j; jj < n; jj++)
        tmp.push_back(nums2[jj]);
    if((m+n)%2==0)
        return double((tmp[m_index]+tmp[m_index-1])/(2+0.0));
    else
        return double(tmp[m_index]);
}   
/*recursion: search k-th big number*/
int find_kth(vector<int>::const_iterator A,int m,vector<int>::const_iterator B,int n ,int k)
{
    // default m < n
    if(m>n) return find_kth(B,n,A,m,k);
    if(m==0) return *(B+k-1);
    if(k==1) return min(*A,*B);

    //divide k into 2 part
    int ia = min(m,k/2), ib = k-ia;
    if(*(A+ia-1)<*(B+ib-1))
        return find_kth(A+ia,m-ia,B,n,k-ia);
    else if(*(A+ia-1)>*(B+ib-1))
        return  find_kth(A,m,B+ib,n-ib,k-ib);
    else
        return *(A+ia-1);
}
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int total = m+n;
    if(total%2==0)
        return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2)
        + find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;
    else
        return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
}


int main(){
    vector<int> nums1={1,2};
    vector<int> nums2={3,4};
    cout<<findMedianSortedArrays1(nums1,nums2)<<endl;
}