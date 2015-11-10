#include <iostream>
#include <cstring>
#include <cstdio>
#define  MAXN_SIZE 400

int  KMP_Math( char * , char * );
void Find_Nextval( char * , int * );

int main( int agrc, char *agrv[] )
{
    char Master[MAXN_SIZE], Match[MAXN_SIZE];

    printf("Please enter the Master serial and the Match serial: ");
    scanf("%s%s", Master, Match );
    int pos = KMP_Math( Master, Match );
    if ( -1 == pos ){
        printf("failed Match.\n");
    }
    else {
        printf("Match successed. the first pos was laction %d.\n", pos );
    }

    return 0;
}
int KMP_Math( char * Master, char * Match )
{
    int i = 0, j = 0;
    int Next[MAXN_SIZE];
    Find_Nextval( Match, Next );

    while ( Master[i] ){
        if ( -1 == j || Master[i] == Match[j] ){
            i++;
            j++;
        }
        else {
            j = Next[j];
        }
        if ( Match[j] == '\0' ){
            return i - j + 1;
        }
    }
    return -1;

}
void Find_Nextval( char * Match, int * Next )
{
    int k = -1, i = 0;
    int len = strlen( Match );
    Next[0] = -1;
    for ( int i = 0; i < len; i++ ){
        i++;
        k++;
        if ( -1 == k || Match[i] == Match[k] ){
            if ( Match[i] == Match[k] ){
                Next[i] = Next[k];
            }
            else {
                Next[i] = k;
            }
        }
        else {
            k = Next[i];
        }
    }
    return ;
}
