#include <stdio.h>
#include <string.h>
#define swap(a, b, t) t = a, a = b, b = t

void perm(char * arr,int k,int len);

int main(void)
{
    char arr[1001];
    gets(arr);

    perm(arr,0,strlen(arr));
}
void perm(char * arr, int k,int len)
{
    int i, j, t;
    if (k == len)
    {
        for (j=0; j<4; j++)
            printf("%c",arr[j]);
        printf("\n" );
    }
    else
    {
        for (i=k; i<len; i++)
        {
            swap(arr[k], arr[i], t);
            perm(arr, k+1,len);
            swap(arr[k], arr[i], t);
        }
    }
}
