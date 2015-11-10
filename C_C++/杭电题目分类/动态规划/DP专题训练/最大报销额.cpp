#include<cstdio>
#include<cstring>
int value[32],dp[4000000];
int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    double Q;
    int N;
    while(scanf("%lf%d",&Q,&N) && N){
        int i,j;
        char ch;
        double price;
        int m,k=0;
        while(N--){
            scanf("%d",&m);
            int numa=0,numb=0,numc=0;
            for(i=0;i<m;i++){
                scanf("%*c%c:%lf",&ch,&price);
                switch(ch){
                    case 'A':numa+=(int)(100*price);break;
                    case 'B':numb+=(int)(100*price);break;
                    case 'C':numc+=(int)(100*price);break;
                    default :numa+=100000;
                }
            }
            if(numa<=60000 && numb<=60000 && numc<=60000 && (numa+numb+numc)<=100000)
                value[k++]=numa+numb+numc;
        }
        memset(dp,0,sizeof(dp));
        int tmp=(int)(Q*100);
        for(i=0;i<k;i++)
            for(j=tmp;j>=value[i];j--)
                if(dp[j]<dp[j-value[i]]+value[i])
                    dp[j]=dp[j-value[i]]+value[i];
        printf("%.2lf\n",dp[tmp]/100.0);
    }
    return 0;
}
