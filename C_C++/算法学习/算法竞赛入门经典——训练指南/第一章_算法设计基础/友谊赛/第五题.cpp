#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 165004;
const int dd[2][13] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n = 1;
    int arrAy[MAXN][3];
    int year(1), month(1), day(1);
    arrAy[1][0] = arrAy[1][1] = arrAy[1][2] = 1;
    while ( ++n < MAXN ){
        if ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ){
            if ( day == dd[1][month-1] ){
                day = 1;
                month++;
            }
            else    day++;
        }
        else {
            if ( day == dd[0][month-1] ){
                day = 1;
                month++;
            }
            else day++;
        }
        if ( month == 13 ){
            year++;
            month = 1;
        }
        arrAy[n][0] = year;
        arrAy[n][1] = month;
        arrAy[n][2] = day;
    }
    while ( ~scanf("%d", &n ) ){
        printf("%d %d %d\n", arrAy[n][0], arrAy[n][1], arrAy[n][2] );
    }

    return 0;
}
