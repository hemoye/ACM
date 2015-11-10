#include <iostream>

using namespace std;

void print( int , int );

int main( void )
{
    int hour, minute;

    cout << "Enter the number of hours: ";
    cin  >> hour;
    cout << "Enter the number of minutes: ";
    cin  >> minute;

    print( hour, minute );

    return 0;
}
void print( int hour, int minute )
{
    cout << "Time: " << hour << ":";
    cout << minute << endl;

    return ;
}
