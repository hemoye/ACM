#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 2000;

using namespace std;

int main(int agrc, char *agrv[])
{
    int result[MAXN];
    char str1[MAXN/2], str2[MAXN/2];

    while ( ~scanf("%s%s", str1, str2)){
        memset(result, 0, sizeof(result));
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        for ( int i = len1 - 1; i >= 0; i-- ){
            for ( int j = len2 - 1; j >= 0; j-- ){
                int temp = (str1[i] - '0') * (str2[j] - '0');
                result[i+j+1] += temp;
            }
        }

        int len = len1 + len2;
        for ( int i = len; i > 0; i-- ){
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
        if (result[0])  printf("%d", result[0]);
        for ( int i = 1; i < len; i++ ) printf("%d", result[i]);
        puts("");
    }

    return 0;
}
