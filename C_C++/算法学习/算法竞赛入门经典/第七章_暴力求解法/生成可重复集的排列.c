#include <stdio.h>
#include <string.h>
#define  Swap( a, b, t ) t = a, a = b, b = t
#define  MAXN 10

void print_pre( int , int * , int * , int );
void Sort( int * , int n );

int total;

int main( void )
{
    int n, i;
    int anwser[MAXN], arrAy[MAXN];

    while ( scanf("%d", &n ) != EOF )
    {
        if ( 0 == n )
            break;

        total = 0;
        printf("Please enter %d number:\n", n);
        for ( i = 0; i < n; i++ )
            scanf("%d", &arrAy[i] );
        Sort( arrAy, n );

        printf("Ok, My anwser as follow:\n");
        print_pre( n, anwser, arrAy, 0 );
        printf("There are %d type to make up.\n", total);
    }

    return 0;
}
void Sort( int * ptr, int n )
{
    int i, j;
    int change = 1;
    int temp;

    for ( i = 1; i < n && change; i++ )
    {
        change = 0;
        for ( j = 0; j < n - i; j++ )
            if ( ptr[j] < ptr[j+1] )
                Swap( ptr[j], ptr[j+1], temp );
    }
}
void print_pre( int n, int * qtr, int * arr, int cur )
{
    int i, j;

    if ( cur == n )
    {
        total++;
        for ( i = 0; i < n; i++ )
            printf("%d", qtr[i]);
        puts("");
    }
    else
    {
        for ( i = 0; i < n; i++ )
            if ( !i || arr[i] != arr[i-1] )
            {
                int c1 = 0, c2 = 0;
                qtr[cur] = arr[i];

                for ( j = 0; j < cur; j++ )
                    if ( qtr[j] == qtr[cur] )
                        c1++;
                for ( j = 0; j < n; j++ )
                    if ( qtr[cur] == arr[j] )
                        c2++;

                if ( c1 < c2 )
                    print_pre( n, qtr, arr, cur + 1 );
            }
    }

    return ;
}
/**
    �ܽ᣺
        �˴��������������
        ��������ǣ�3
                     1 2 1ʱ�����ܹ���ȷ���������
        ����������Ƚ���һ������Ȼ���ٽ����������
**/
