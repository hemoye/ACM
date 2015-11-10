#include <cstdio>
#include <cstring>
#define MAXN 1000
int a[MAXN];
int fun(int n, int m)
{
    a[0] = 1;
    int len = 1;
    int i = n;
    while ( m -- ) {
        int c = 0;
        for (int j = 0; j < len; j ++){
            int s = a[j] * i + c;
            a[j] = s % 10;
            c = s / 10;
            if ( c && j == len - 1 ){
                len ++;
            }
        }
        i --;
    }
    return len;
}
void division(int n, int& len)
{
    int i, k, t=0, s=0;
    int dest[MAXN];
    bool flag = true;
    for(i=0,k=0; i < len; i++)
    {
        t = s*10 + a[len-1-i];
        if(t/n>0 || t==0)
        {
            dest[k++] = t/n;
            s = t%n;
            flag = false;
        }
        else
        {
            s = t;
            if(!flag)
                dest[k++] = 0;
        }
    }
    for (int i = 0; i < k; i ++) a[k-i-1] = dest[i];
    len = k;
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while ( T -- ) {
        int k, n;
        memset(a, 0, sizeof(a));
        scanf("%d %d", &k, &n);
        int len = fun(n+k-1, k-1);
        for (int i = 2; i <= k-1; i ++) {
            division(i, len);
        }
        for (int i = len-1; i >= 0; i --)    printf("%d", a[i]);
        puts("");
    }
    return 0;
}
