#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b;

int main(int agrc, char *agrv[])
{
    while (~scanf("%d%d", &a, &b)){
        if (a < b){
            int temp = a;
            a = b;
            b = temp;
        }
        int d = b - a;
        int t = floor(d * (sqrt(5.0) + 1 ) / 2 );
        puts((t == a)?"0":"1");
    }

    return 0;
}
