#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1000;

using namespace std;

int main(int agrc, char *agrv[])
{
    int n;
    int result[MAXN];
    char str[MAXN];

    while (~scanf("%s%d", str, &n)){
        int len = strlen(str);

        int c(0);
        for ( int i = len - 1; i >= 0; i-- ){
            int temp = (str[i] - '0') * n + c;
            result[i] = temp % 10;
            c = temp / 10;
        }
        if (c)  printf("%d", c);
        for ( int i = 0; i < len; i++ ) printf("%d", result[i]);
        puts("");
    }

    return 0;
}
