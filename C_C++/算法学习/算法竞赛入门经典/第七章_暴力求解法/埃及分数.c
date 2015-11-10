#include<stdio.h>
#include<string.h>
#define MAXD 100

int depth , max , cmdepth ;  //全局变量初始为0 , 深度， 分母的最大数， 限定分母的最大深度(分母最大个数)
int ans[MAXD] , out[MAXD] ;  //当前分母 和 要输出的分母

void find(int a , int b , int x) //x为构造的当前分母
{
    if( depth >= cmdepth || x >= max )   return ; //叶子结点的处理
    if( b%a == 0 )  //最后一组情况
    {
        b /= a ;
        if( b < x || b >= max ) return ;
        ans[depth] = b ;
        max = b ;
        memcpy(out , ans , sizeof(ans)) ;
        // printf("depth = %d\n" , depth) ;
        return;
    }
    else
    {
        if ( depth >= cmdepth-1 )  return ;  //到达叶子结点终止
        while ( a*x <= b && x < max )    ++ x ;
        while ( x < max )
        {
            if ( a*x >= b*(cmdepth-depth) )  break ;
            ans[depth] = x ;
            ++ depth ;
            // printf("a = %d   " , a) ;
            // printf("b = %d\n" , b) ;
            find(a*x-b , b*x , x+1) ;
            -- depth ;
            // printf("a = %d   " , a*x-b) ;
            //  printf("b = %d\n" , b*x) ;
            ++ x ;
        }
    }
    return ;
}
int main(void)
{
//	#ifndef ONLINE_JUDGE
//		freopen("test.in", "r", stdin);
//		freopen("test.out", "w", stdout);
//	#endif
    int a , b , k ;
    scanf("%d/%d" , &a , &b) ;
    max = 1000000 ;
    for (cmdepth = 1 ; cmdepth <= MAXD ; ++ cmdepth)
    {
        find(a , b , 1) ;
        //printf("cmdepth = %d\n", cmdepth );
        if ( max < 1000000 )     break ;

    }
    printf("%d/%d =" , a , b) ;
    for (k = 0 ; k < cmdepth-1 ; ++ k)   printf(" 1/%d +" , out[k]) ;
    printf(" 1/%d\n" , out[cmdepth-1]) ;
    return 0;
}
