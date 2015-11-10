#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m%n);
}

int main(int agrc, char *agrv[])
{
    int m, n;
    while (~scanf("%d%d", &m, &n)){
        printf("%d\n", gcd(m, n));
    }

    return 0;
}
