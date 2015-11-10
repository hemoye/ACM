#include <iostream>
#define  MAXSIZE 40

struct job
{
    char name[MAXSIZE];
    double salary;
    int floor;
} ;

template <class Any>
void Swap( Any & , Any & );
template <> void Swap<job>( job & j1, job & j2 );
void Swap( int & a, int & b );
void Show( job & );

int main( void )
{
    using namespace std;

    int i = 4, j = 24;

    cout << "i = " << i << ", j = " << j << endl;
    Swap( i, j );                                              /**首先调用的是void Swap( int & a, int & b )
                                                               若是没有才会调用template <class Any>
                                                                                void Swap( Any & , Any & )**/
    cout << "Now " << "i = " << i << ", j = " << j << endl;

    job susan = { "Susan Yaffee", 73000.60, 7 };
    job sdney = { "Sdney Taffee", 78060.72, 9 };
    Show( susan );
    Show( sdney );
    Swap( susan, sdney );
    cout << "After Swap:" << endl;
    Show( susan );
    Show( sdney );

    return 0;
}

template <class Any>
void Swap( Any & a, Any & b )
{
    Any temp = a;
    a = b;
    b = temp;

    return ;
}

template <> void Swap<job>( job &j1, job &j2 )
{
    double tl;
    int t2;

    tl = j1.salary;
    t2 = j1.floor;
    j1.salary = j2.salary;
    j1.floor = j2.floor;
    j2.salary = tl;
    j2.floor = t2;

    return ;
}
void Swap( int & a, int & b )
{
    int temp = a;
    a = b;
    b = temp;

    return ;
}
void Show( job & j )
{
    using namespace std;

    cout << j.name << ": $" << j.salary
         << " on floor " << j.floor << endl;
    return ;
}
