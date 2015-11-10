#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1004;

int main(int agrc, char *agrv[])
{
    int arrAy[MAXN];
    char str[MAXN];

    while (~scanf("%s", str)){
        int flage(0), count(0);
        int len = strlen(str);
        memset(arrAy, 0, len);
        for (int i = 0; i < len; ){
            if ('5' == str[i]) i++;
            while ('5' != str[i] && i < len){
                flage = 1;
                arrAy[count] = arrAy[count] * 10 + (str[i] - '0');
                i++;
            }
            if (flage){
                count++;
                flage = 0;
            }
        }
        sort(arrAy, arrAy + count);
        for (int i = 0; i < count; i++)    printf(0 == i ? "%d" : " %d", arrAy[i]);
        puts("");
    }

    return 0;
}
