#include<stdio.h>
#define  swap(a, b, t) t = a, a = b, b = t
 int a[4],b[4];
 int max(int *q)
 {
     int x,i,j,t;
     for(i=0;i<4;i++)
     for(j=i+1;j<4;j++)
     if(q[i]<q[j])
        {
             swap(q[i],q[j],t);
        }
         return(q[0]*1000+q[1]*100+q[2]*10+q[3]);
 }
 int min(int *q)
 {
     int x,i,j,t;
     for(i=0;i<4;i++)
     for(j=i+1;j<4;j++)
     if(q[i]>q[j])
         swap(q[i],q[j],t);
         return(q[0]*1000+q[1]*100+q[2]*10+q[3]);
 }
int main()
{
    freopen("test.in", "r", stdin);

   int s,time=0,n;
   int x,y,m;
   scanf("%d",&n);
    while(n--)
    {
        time = 0;
        scanf("%d",&s);
        b[0]=a[0]=s/1000;
        b[1]=a[1]=s%1000/100;
        b[2]=a[2]=s%100/10;
        b[3]=a[3]=s%10;
        while(1)
        {time++;
           x=max(a);
           y=min(b);
           m=x-y;
           printf("%d %d %d\n",x,y,m);
           if(m==s)break;
           else {
               s=m;
                 b[0]=a[0]=s/1000;
        b[1]=a[1]=s%1000/100;
        b[2]=a[2]=s%100/10;
        b[3]=a[3]=s%10;
        

           }

        }
    }
}