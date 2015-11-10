#include <stdio.h>
int judge(int n)
{
    if(n%4==0&&n%100!=0||n%400==0)
        return 1;
    return 0;
}
int main(void)
{
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int s=0, i, j, b[7] = {0}, n, t=0;
    scanf("%d", &n);
    for(i=1900; i<1900+n; i++)
    {
        for(j=0; j<12; j++)
        {
            if(judge(i)&&j==1)
                s = a[j]+ 1;
            else
                s = a[j];
            b[(13+t)%7]++;
            t += s%14;
        }
    }
    printf("%d %d ", b[6], b[0]);
    for(i=1; i<6; i++)
        printf((i<5)?"%d ":"%d", b[i]);
    return 0;
}
