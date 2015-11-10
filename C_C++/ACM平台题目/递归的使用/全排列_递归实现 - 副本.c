#include <stdio.h>
#include <string.h>

void perm(char * arr,int k,int len);
void swap(char *p,char *q);

int main(void)
{
    char arr[1001];
    gets(arr);

    perm(arr,0,strlen(arr));
}
void perm(char * arr, int k,int len)
{
    int i, j, t;
    if (k==len-2)
    {
        for (j=0; j<len; j++)
            printf("%c",arr[j]);
        printf("\n" );
        for (j=0; j<len-2; j++)
            printf("%c",arr[j]);
        printf("%c%c\n",arr[len-1], arr[len-2]);
    }
    else
    {
        for (i=k; i<len; i++)
        {
            swap(&arr[k], &arr[i]);
            perm(arr, k+1,len );
            swap(&arr[k], &arr[i]);
        }
    }
}
void swap(char *p,char *q)//½»»»Öµ
{
    char c;
    c=*p;
    *p=*q;
    *q=c;
}
