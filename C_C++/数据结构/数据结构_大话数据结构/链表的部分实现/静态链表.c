#include <stdio.h>
#include <stdlib.h>
#define  MAX 1000

typedef struct
{
    int data;
    int cur;
} node;

int main( void )
{
    node Node[MAX];
    int i = 0;

    while ( 1 )
    {
        Node[i].cur = i + 1;
        scanf("%d", &Node[i].data);
        if ( 0 == Node[i].data )
            break;

        i++;
        Node[i].cur = 0;
    }

    i = 0;
    while ( Node[i].data )
    {
        printf("%d ", Node[i].data);
        i++;
    }

    return 0;
}
