#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int main(int agrc, char *agrv[])
{
    int m, n;

    while (~scanf("%d%d", &m, &n)){
        printf("%10d %10d    ", m, n);
        if (1 == gcd(m, n)) puts("Good Choice");
        else    puts("Bad Choice");
    }

    return 0;
}
