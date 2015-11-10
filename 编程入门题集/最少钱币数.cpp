#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 12;

using namespace std;

int money, num;
int arrAy[MAXN];

int Judge()
{
    int k = 0;
    for ( int i = num - 1; i >= 0; i-- ){
        while( money / arrAy[i] ){
            money -= arrAy[i];
            k++;
        }
    }
    return k;
}

int main( int agrc, char *agrv[] )
{
    while (~scanf("%d", &money)&&money){
        scanf("%d", &num);
        for (int i = 0; i < num; i++)   scanf("%d", &arrAy[i] );
        sort(arrAy, arrAy+num);
        int temp = Judge();
        if (!temp)  printf("Impossible\n");
        else    printf("%d\n", temp);
    }

    return 0;
}
