#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int agrc, char *agrv[])
{
    int n;

    while (~scanf("%d", &n))    printf(2 == n % 4 ? "yes\n" : "no\n");

    return 0;
}
