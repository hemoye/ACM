#include <stdio.h>
#define  MAX 101

struct Node
{
    int price;
    int bluk;
};

int main( void )
{
    int v, n, i, j;

    while ( scanf("%d", &v) != EOF )//口袋的体积
    {
        if ( 0 == v )//体积为0时终止计算
            break;

        scanf("%d", &n);//输入宝贝的种类

        struct Node stud[MAX], temp;
        int total = 0;

        for ( i = 0; i < n; i++ )
            scanf("%d%d", &stud[i].price, &stud[i].bluk);

        for ( i = 1; i < v; i++ )
            for ( j = 0; j < v - i; j++ )
                if ( stud[j].price < stud[j+1].price )
                {
                    temp = stud[j];
                    stud[i] = stud[j+1];
                    stud[j+1] = temp;
                }

        for ( i = 0; v ; i++ )
        {
            if ( v > stud[i].bluk )
            {
                total += stud[i].bluk * stud[i].price;
                v -= stud[i].bluk;
            }
            else
            {
                total += stud[i].price * v;
                v = 0;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}
