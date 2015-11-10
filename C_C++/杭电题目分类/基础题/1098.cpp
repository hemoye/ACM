#include <cstdio>

int main(int agrc, char *agrv[])
{
    int k;
    while (~scanf("%d", &k)){
        bool flag = true;
        for (int i = 1; i < 65; i++){
            if (0 == (18 + i * k) % 65){
                printf("%d\n", i);
                flage = false;
            }
        }
        if (flag)  puts("no");
    }

    return 0;
}
