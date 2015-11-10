#include <cstdio>
#include <cmath>

bool is_prime(int n)
{
    int x = sqrt((double)n);
    for (int i = 2; i <= x; i++)    if (0 == n % i) return false;
    return true;
}

int main(int agrc, char *agrv[])
{
    int n;

    while (~scanf("%d", &n)){
        for (int i = 2; i <= n; i++){
            if (is_prime(i)){
                if (0 == n % i){
                    n /= i;
                    printf("%d", i);
                    break;
                }
            }
        }
        for (int i = 2; i <= n; i++){
            if (is_prime(i)){
                while (0 == n % i){
                    n /= i;
                    printf("*%d", i);
                }
            }
        }
        puts("");
    }

    return 0;
}
