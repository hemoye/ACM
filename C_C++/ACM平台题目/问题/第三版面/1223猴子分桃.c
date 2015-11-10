#include <stdio.h>
void main(void)
{
    int base=0;
    int cuurent=base;
    int count=0;
    int mon=1;

   // bool flag=true;

    while(mon<5)
    {
        flag=resv(cuurent,count,mon);
        if(flag)
        {
            cuurent=count;
            mon++;
        }
        else
        {
            mon=1;
            base++;
            cuurent=base;
        }
    }
    printf("ÌÒ×Ó×ÜÊý:%d",count);

}

bool resv(int cuurent,int &count,int mon)
{
    if((cuurent%4)!=0)
        return false;

    count=(cuurent/4)*5+1;

    return true;
}
