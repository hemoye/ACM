#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[50],b[50];
    int i,j,next[50],v,vv,num;
    gets(a);
    gets(b);
    i=0;
    j=0;
    while(a[i]!='\0')i++;
    while(b[j]!='\0')j++;
    next[0]=-1;
    v=0;
    vv=-1;
    while(v<j-1)
    {
        if(vv==-1||(b[v]==b[vv]))
        {
            v++;
            vv++;
            next[v]=vv;
        }
        else
        {
            vv=next[vv];
        }
    }
    for ( i = 0; b[i]; i++ ){
        printf("%d ", next[i] );
    }
    puts("");
    vv=0;
    num=1;
    for(v=0; v<i; v++)
    {
        if(a[v]==b[vv])
        {
            vv++;
        }
        else
        {
            v--;
            vv=next[vv];
            num++;
        }
        if(vv==j)
        {
            printf("%d %d",num,v+1-j+1);
            break;
        }
    }
    return 0;
}
