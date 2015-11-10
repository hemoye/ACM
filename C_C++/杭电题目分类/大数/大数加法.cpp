#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1004;

using namespace std;

int main(int agrc, char *agrv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif
    int n;
    int result[MAXN];
    char str1[MAXN], str2[MAXN];

    scanf("%d", &n);
    for (int kas = 1; kas <= n; kas++){
        scanf("%s%s", str1, str2);
        memset(result, 0, sizeof(result));

        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int len = len1 > len2 ? len1 : len2;

        int i = len;

        int c1, c2;
        while (len1 > 0 || len2 > 0){
            if (len1 <= 0)  c1 = 0;
            else    c1 = str1[len1-1] - '0';
            if (len2 <= 0)  c2 = 0;
            else    c2 = str2[len2-1] - '0';

            result[i--] = c1 + c2;
            len1--;
            len2--;
        }
        for ( int i = len; i > 0; i-- ){
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
        printf("Case %d:\n", kas);
        printf("%s + %s = ", str1, str2);
        if (result[0])  printf("%d", result[0]);
        for ( int i = 1; i <= len; i++ ) printf("%d", result[i]);
        puts("");
        if (n - kas) puts("");
    }

    return 0;
}
