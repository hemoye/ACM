#include <cstdio>
#include <cstring>
#define  MAXN 1004
#define  Swap( a, b, t ) t = a, a = b, b = t

int main( int agrc, char *agrv[] )
{
//    freopen( "in.in", "r", stdin );
    int N;
    char str[MAXN];
    scanf("%d%*c", &N );
    while ( N-- ){
        gets(str);
        int len = strlen( str );
        int numA(0), numB(0), numC(0);
        for ( int i = 0; i < len; i++ ){
            if ( 'A' == str[i] )    numA++;
            else if ( 'B' == str[i] )   numB++;
            else    numC++;
        }
        numB += numA;
        char temp;
        int total(0);
        for ( int i = 0; i < numA; i++ ){
            if ( 'B' == str[i] ){
                bool ok = true;
                for ( int j = numA; j < numB; j++ ){
                    if ( 'A' == str[j] ){
                        Swap( str[i], str[j], temp );
                        total++;
                        ok = false;
                        break;
                    }
                }
                if ( ok ) {
                    for ( int j = numB; j < len; j++ ){
                        if ( 'A' == str[j] ){
                            Swap( str[i], str[j], temp );
                            total++;
                            break;
                        }
                    }
                }
            }
            else if ( 'C' == str[i] ){
                bool ok = true;
                for ( int j = numB; j < len; j++ ){
                    if ( 'A' == str[j] ){
                        Swap( str[i], str[j], temp );
                        total++;
                        ok = false;
                        break;
                    }
                }
                if ( ok ) {
                    for ( int j = numA; j < numB; j++ ){
                        if ( 'A' == str[j] ){
                            Swap( str[i], str[j], temp );
                            total++;
                            break;
                        }
                    }
                }
            }
        }
        for ( int i = numA; i < numB; i++ ){
            if ( 'C' == str[i] ){
                for ( int j = numB; j < len; j++ ){
                    if ( 'B' == str[j] ){
                        Swap( str[i], str[j], temp );
                        total++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", total );
    }

    return 0;
}
