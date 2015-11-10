#include <iostream>

using namespace std;

int main( void )
{
    int n, data;
    int ThisSum( 0 ), MaxSum( 0 );

    cout << "Please enter the size of the arra: ";
    cin >> n;
    cout << "Please enter the n elements: ";
    for ( int i = 0; i < n; i++ ){
        cin >> data;
        ThisSum += data;
        if ( ThisSum > MaxSum ){
            MaxSum = ThisSum;
        }
        else if ( ThisSum < 0 ){
            ThisSum = 0;
        }
    }
    cout << "The largest sub-segment and is : " << MaxSum << endl;

    return 0;
}
