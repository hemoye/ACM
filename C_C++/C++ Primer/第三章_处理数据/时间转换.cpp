#include <iostream>

int main( void )
{
    using namespace std;

    const int HOUR = 24;
    const int CHANGE = 60;
    long total;
    int second, minute, hour, day;

    cout << "Enter the number of seconds: ";
    cin  >> total;
    cout << total << " seconds = ";

    second = total % CHANGE;
    minute = total / CHANGE;
    hour = minute / CHANGE;
    minute %= CHANGE;
    day = hour / HOUR;
    hour %= HOUR;

    cout << day << " days " << hour << " hours ";
    cout << minute << " minutes ";
    cout << second << " seconds." << endl;

    return 0;
}
