#include <cstdio>
#include <cstring>
#define MAXN    100
int arr[MAXN] , m , n  , str[MAXN];

void search(int begin , int pos , int n) {
        if(pos == n) {
                for(int i = 0 ; i < n ; i ++) {
                        printf(i?" %d":"%d" , str[i]) ;
                }
                puts("") ;
        }
        for(int i = begin ;  i < m ; i ++) {
                if(arr[i] == 0){
                        arr[i] = 1 ;
                        str[pos] = i + 1 ;
                        search(str[pos] , pos + 1 , n) ;
                        arr[i] = 0 ;
                }
        }
}

int main(int argc, char const *argv[])
{
        int cas ,sum = 0;
        scanf("%d" , &cas) ;
        for(int i = 0 ; i < cas ; i ++) {
                scanf("%d %d" , &m , &n) ;
                for(int i = 0 ; i < m ; i ++) {
                        arr[i] = 0 ;
                }
                printf("Case #%d:\n", ++ sum);
                search(0 , 0 , n) ;
        }
        return 0;
}
