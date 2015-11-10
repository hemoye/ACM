#include <iostream>

using namespace std;

int change( float );

int main( void )
{
    float temp;

    cout << "Please enter a Celsius value: ";
    cin  >> temp;
    cout << temp << " degrees Celsius is ";
    cout << change( temp ) << " degrees Fahrenheit.";
    cout << endl;

    return 0;
}
int change( float temp )
{
    return 1.8 * temp + 32.0;
}
