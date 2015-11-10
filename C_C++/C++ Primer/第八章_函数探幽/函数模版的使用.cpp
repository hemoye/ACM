#include <iostream>

template <class Any>
Any MAX( Any ptr[], int );

int main( void )
{
    using namespace std;

    const int n = 5;

    int INTarrAy[n];
    for ( int i = 0; i < n; i++ )
        cin >> INTarrAy[i];
    cout << "The MAX elment is: " << MAX( INTarrAy, n ) << endl;

    double DOUarrAy[n];
    for ( int i = 0; i < n; i++ )
        cin >> DOUarrAy[i];
    cout << "The MAX elment is: " << MAX( DOUarrAy, n ) << endl;

    return 0;
}

template <class Any>
Any MAX( Any ptr[], int n )
{
    using namespace std;

    Any max = ptr[0];

    for ( int i = 1; i < n; i++ )
        if ( max < ptr[i] )
            max = ptr[i];
    return max;
}
