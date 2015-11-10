#include <iostream>

using namespace std;

float change( float );

int main( void )
{
    float year;

    cout << "Enter the number of light years:";
    cin  >> year;
    cout << year << " light years = ";
    cout << change( year ) << " astronomical units.";
    cout << endl;

    return 0;
}
float change( float year )
{
    return year * 63240;
}
