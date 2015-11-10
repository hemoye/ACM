#include <iostream>
#include <cstring>
#include "class.cpp"
#define  MAX 40
#define  SIZE 4

int main( void )
{
    Stock stock[SIZE] =
    {
        Stock ("NanoSmart", 12, 5.20),
        Stock ("Boffo Objects", 200, 2.0),
        Stock ("Monolithic Obelisks", 130, 3.25),
        Stock ("Fleep Enterprises", 60, 6.5)
    };
    for ( int i = 0; i < SIZE; i++ )
        stock[i].show();                              //展示持股人所拥有的股票信息

//    stock[1].buy ( 15, 18.25 );                       //买进股票（数量、单价）
//    stock[1].show();                                  //展示持股人所拥有的股票信息
//    stock[1].sell ( 400, 20.00 );                     //卖出股票（数量、单价）
//    stock[1].show();                                  //展示持股人所拥有的股票信息

    Stock top = stock[0];
    for ( int i = 1; i < SIZE; i++ )
        top = top.topval( stock[i] );
    std::cout << "\nMost valuable holding: \n";
    top.show();

    std::cout << "Done.\n";

    return 0;
}
