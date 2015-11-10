#include <iostream>

int main( void )
{
    using namespace std;

    char ch;

    while ( ( ch = cin.get() ) != '@' )
    {
        if ( ch >= 'a' && ch <= 'z' )
            ch -= 32;
        else if ( ch >= 'A' && ch <= 'Z' )
            ch += 32;
        else if ( ch >= '0' && ch <= '9' )
            continue;
        cout << ch;
    }
    cout << endl;

    return 0;
}
