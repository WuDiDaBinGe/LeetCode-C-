#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
char s[maxn];
unordered_map <char,int> p;
int ans;

int main()
{
    scanf("%s",s+1); int len=strlen(s+1);
    p['0']=0; p['1']=1; p['2']=1; p['3']=2; p['4']=1;
    p['5']=2; p['6']=2; p['7']=3; p['8']=1; p['9']=2;
    p['A']=2; p['B']=3; p['C']=2; p['D']=3; p['E']=3; p['F']=4;
    rep(i,1,len) ans+=p[s[i]];
    cout<<ans<<endl;
	return 0;
}
