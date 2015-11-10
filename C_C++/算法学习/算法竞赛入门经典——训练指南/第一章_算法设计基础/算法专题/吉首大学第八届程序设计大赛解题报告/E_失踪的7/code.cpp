#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define W_CNT   6
#define MAXN    10 + 10
#define MAXM    500 + 10
#define INF     0x3f3f3f3f
#define REPD(i, e, s)   for(int i = (e); i >= (s); i --)
#define REPI(i, s, e)   for(int i = (s); i <= (e); i ++)
 
int n[MAXN];
char num[MAXN];
 
long long get_pow(int down, int up)
{
 
        long long rst = 1;
        REPI(i, 1, up) {
                rst *= down;
        }
        return rst;
}
 
long long cal(int l, int r)
{
        if( l == r ) {
                return (n[l] > 7)? n[l]-1 : n[l];
        }
        if( n[l] <= 0 ) {
                return cal(l+1, r);
        }
        if( n[l] == 7 ) {
                n[l] -= 1;
                return cal(l, r);
        }
        n[l] -= 1;
        return get_pow(9, r-l)+cal(l, r);
}
 
int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
        freopen("test.in", "r", stdin);
#endif
        while( ~scanf("%s", num) ) {
                int len = strlen(num)-1;
                REPI(i, 0, len) {
                        n[i] = num[i]-'0';
                }
                printf("%lld\n", cal(0, len));
        }
}

/**************************************************************
    Problem: 5499
    User: Pascal
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:964 kb
****************************************************************/
