//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 5842 + 1;
//
//int main(int agrc, char *agrv[])
//{
//    int n;
//    int arrAy[MAXN];
//    int p1, p2, p3, p4;
//
//    arrAy[1] = 1;
//    p1 = p2 = p3 = p4 = 1;
//
//    for (int i = 2; i < MAXN; i++){
//        arrAy[i] = min(min(arrAy[p1]*2, arrAy[p2]*3), min(arrAy[p3]*5, arrAy[p4]*7));
//        if (arrAy[i] == arrAy[p1]*2)   p1++;
//        if (arrAy[i] == arrAy[p2]*3)   p2++;
//        if (arrAy[i] == arrAy[p3]*5)   p3++;
//        if (arrAy[i] == arrAy[p4]*7)   p4++;
//    }
//
//    while (~scanf("%d", &n) && n){
//        if (1 == n % 10)    printf("The %dst humble number is %d.\n", n, arrAy[n]);
//        else if (2 == n % 10)    printf("The %dnd humble number is %d.\n", n, arrAy[n]);
//        else if (3 == n % 10)    printf("The %drd humble number is %d.\n", n, arrAy[n]);
//        else    printf("The %dth humble number is %d.\n", n, arrAy[n]);
//    }
//
//    return 0;
//}
#include <iostream>
#include <algorithm>
using namespace  std;
#define  N 5842
int values[N + 1] ;

inline int minValue(int n1, int n2, int n3, int n4)
{
    return min(min(n1, n2), min(n3, n4)) ;
}

int main(int argc, char ** argv)
{
    values[1] = 1 ;
    int p1, p2, p3, p4 ;
    p1 = p2 = p3 = p4 = 1 ;

    for (int i = 2; i <= N; ++ i)
    {
        values[i] = minValue(values[p1] * 2, values[p2] * 3, values[p3] * 5, values[p4] * 7) ;
        if (values[p1] * 2 == values[i]) p1 ++ ;
        if (values[p2] * 3 == values[i]) p2 ++ ;
        if (values[p3] * 5 == values[i]) p3 ++ ;
        if (values[p4] * 7 == values[i]) p4 ++ ;
    }

    int inValue ;
    while(cin >> inValue && inValue != 0)
    {
        if (inValue % 100 == 11 || inValue % 100 == 12 || inValue % 100 == 13)
            cout << "The "<< inValue << "th humble number is " <<values[inValue]<< "." << endl;
        else
            if (inValue % 10 == 1)
                cout << "The "<< inValue << "st humble number is " <<values[inValue]<< "." << endl;
            else
                if (inValue % 10 == 2)
                    cout << "The "<< inValue << "nd humble number is " <<values[inValue]<< "." << endl;
                else
                    if (inValue % 10 == 3)
                        cout << "The "<< inValue << "rd humble number is " <<values[inValue]<< "." << endl;
                    else
                        cout << "The "<< inValue << "th humble number is " <<values[inValue]<< "." << endl;
    }
    return 0 ;
}
