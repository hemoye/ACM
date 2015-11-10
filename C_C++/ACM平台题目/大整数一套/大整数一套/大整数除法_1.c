#include<stdio.h>
#include<stdlib.h>

main()
{
    char c1[30]= {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9}    ;
    char c2[7]= {3,4,5,3,5,3,5};
    int i,j ,count1=0,count2=0;
    char s[8];
    for(i=0; i<30; i++)
    {
        if(c1[i]!=NULL)
            count1++;
        if(c2[i]!=NULL)
            count2++;
    }
    if(count1<count2)
        printf("除数太小，不够除的....");
    for(i=0; i<count2; i++)
    {
        if(c1[i]<c2[i])
        {
            printf("除数不够除的！");
            break;
        }
        if(c1[i]==c2[i])
        {
            continue;
        }
        if(c1[i]>c2[i])
        {
            for(j=9; j>0; j--)
            {
                if(c2[count2]*j/(count2-1)>c1[i])
                {
                    continue;
                }
                s[i]=j;
            }
        }
    }
}
