#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 2e7 + 5;
char p[MAXN], s[MAXN];
int pl, sl, z[MAXN], ext[MAXN];

void getZ() {
    z[0] = pl;//从0号位置开始，LCP就是全部字符串
    //从1开始，先暴力算
    int now = 0;
    while (now + 1 < pl && p[now] == p[now + 1]) now++;
    z[1] = now;
    int p0 = 1;
    for (int i = 2; i < pl; ++i) {
        if (i + z[i - p0] < p0 + z[p0]) {
            z[i] = z[i - p0];//第一种情况
        } else {
            now = p0 + z[p0] - i;
            now = max(now, 0);
            while (now + i < pl && p[now] == p[now + i]) now++;
            z[i] = now;
            p0 = i;
        }
    }
}

void exkmp() {
    getZ();
    //先暴力算ext[0]
    int now = 0;
    while (now < pl && now < sl && p[now] == s[now]) now++;
    ext[0] = now;
    int p0 = 0;
    for (int i = 1; i < sl; ++i) {
        if (i + z[i - p0] < p0 + ext[p0]) {
            ext[i] = z[i - p0];
        } else {
            now = p0 + ext[p0] - i;
            now = max(now, 0);//防止i太大
            while (now < pl && now + i < sl && p[now] == s[now + i]) now++;
            ext[i] = now;
            p0 = i;
        }
    }
}

int main() {
    scanf("%s%s", s, p);
    pl = strlen(p);
    sl = strlen(s);
    exkmp();
    long long a0 = 0, a1 = 0;
    for (int i = 0; i < pl; ++i) {
        a0 ^= 1LL * (i + 1) * (z[i] + 1);
    }
    for (int i = 0; i < sl; ++i) {
        a1 ^= 1LL * (i + 1) * (ext[i] + 1);
    }
    printf("%lld\n%lld\n", a0, a1);
    return 0;
}