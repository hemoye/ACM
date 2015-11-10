#include <iostream>
#include <cstring>
#include "class.cpp"
#define  MAX 20

int main( void )
{

    Stock stock1("Xieshen", "0000000000000000001", 400000.00);         //银行开户存入40W

    stock1.show();
    stock1.memory( 18.25 );
    stock1.show();
    stock1.draw( 20.00 );
    stock1.show();
    stock1.draw( 500000 );
    stock1.show();
    stock1.memory( 30 );
    stock1.show();
    std::cout << "Done.\n";

    return 0;
}
