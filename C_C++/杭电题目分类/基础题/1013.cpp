#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1004;

using namespace std;

int sum(int n)
{
    int sum(0);
    while (n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(int agrc, char *agrv[])
{
    char str[MAXN];

    while (~scanf("%s", str) && str[0] != '0'){
        int n(0);
        int len = strlen(str);
        for (int i = 0; i < len; i++)   n += str[i] - '0';
        while (n > 9)   n = sum(n);
        printf("%d\n", n);
    }

    return 0;
}
