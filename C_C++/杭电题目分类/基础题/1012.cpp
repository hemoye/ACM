#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int agrc, char *agrv[])
{
    int i;
    double sum = 2.5, m = 2;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    for(i = 3; i <= 9; i++){
        m *= i;
        sum += 1 / m;
        printf("%d %.9lf\n",i,sum);
    }
    return 0;
}
