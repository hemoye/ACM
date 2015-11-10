#include <iostream>

int ReCude( int & );

int main( void )
{
    int n;

    std::cin >> n;
    std::cout << ReCude( n ) << std::endl;

    return 0;
}
int ReCude( int & a )
{
    return a * a * a;
}
