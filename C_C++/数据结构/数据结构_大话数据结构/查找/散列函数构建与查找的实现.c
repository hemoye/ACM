#include <stdio.h>
#include <stdlib.h>
#define  NULLKEY -32768
#define  ERROR -1
#define  MAX 12

typedef struct
{
    int elem;
    int count;
} HashTable;

void InitTable( HashTable * H );
void InTable( HashTable * H );
int  Search( HashTable * H, int );
int  Hash( int n );

int main( void )
{
/*    freopen("in.txt", "r", stdin);*/
    freopen("out.txt", "w", stdout);

    HashTable * H = ( HashTable * )malloc( MAX * sizeof ( HashTable ) );
    int key, temp;

    InitTable( &H );
    InTable( &H );

    while ( scanf("%d", &key) != EOF )
    {
        if ( 0 == key )
            break;

        temp = Search( &H, key );
        if ( temp == ERROR )
            printf("查找失败！元素%d不存在于该表中.\n", key);
        else
            printf("查找成功！元素%d位于表中的第%2d位置.\n", key, temp + 1);
    }

    return 0;
}
void InitTable( HashTable * H )
{
    int i;

    H->count = 0;
    for ( i = 0; i < MAX; i++ )
        H[i].elem = NULLKEY;

    return ;
}
void InTable( HashTable * H )
{
    int key, temp;

    while ( scanf("%d", &key) != EOF )
    {
        if ( 0 == key )
            break;
        temp = Hash( key );

        while ( H[temp].elem != NULLKEY )
            temp = Hash( temp + 1 );

        H[temp].elem = key;
        H->count++;
    }

    return ;
}
int Search( HashTable * H, int key )
{
    int temp = Hash( key );

    while ( H[temp].elem != key )
    {
        temp = Hash( temp + 1);

        if ( H[temp].elem == NULLKEY || temp == Hash( key ) )
            return ERROR;
    }

    return temp;
}
int Hash( int key )
{
    return key % MAX;
}
