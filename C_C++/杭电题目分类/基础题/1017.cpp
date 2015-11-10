#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int agrc, char *agrv[])
{
    int N;

    while (~scanf("%d", &N)){
        int m, n;
        for (int kas = 0; kas < N; kas++){
            if (kas)    puts("");
            int kase(1);
            while (~scanf("%d%d", &m, &n) && m + n){
                int count(0);
                for (int i = 1; i < m; i++){
                    for (int j = 1; j < i; j++){
                        if (0 == (i*i+j*j+n) % (i*j))   count++;
                    }
                }
                printf("Case %d: %d\n", kase++, count);
            }
        }
    }

    return 0;
}
