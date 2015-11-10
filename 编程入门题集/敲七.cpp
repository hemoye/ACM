#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 5;
using namespace std;

int main(int agrc, char *agrv[])
{
    int n;

    while(~scanf("%d", &n)){
        for ( int i = 7; i <= n; i++ ){
            bool flage(false);
            if (!(i%7)) printf("%d\n", i);
            else {
                int temp(i), num(0);
                for ( int j = 0; j < MAXN; j++ ){
                    if (temp%10==7){
                        flage = true;
                        break;
                    }
                    temp /= 10;
                    if (!temp)  break;
                }
                if (flage)  printf("%d\n", i);
            }
        }
    }

    return 0;
}
