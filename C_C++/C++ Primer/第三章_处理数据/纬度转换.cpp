#include <iostream>

int main( void )
{
    using namespace std;

    const int number = 60;
    float degree, minute, second;

    cout << "First , enter the degrees: ";
    cin  >> degree;
    cout << "Next , enter the minutes of arc: ";
    cin  >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin  >> second;
    cout << degree << " degrees " << minute << " minutes ";
    cout << second << " seconds = ";
    cout << degree + minute / number + second / number / number;
    cout << " degrees." << endl;

    return 0;
}
