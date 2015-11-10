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
        stock[i].show();                              //չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ

//    stock[1].buy ( 15, 18.25 );                       //�����Ʊ�����������ۣ�
//    stock[1].show();                                  //չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ
//    stock[1].sell ( 400, 20.00 );                     //������Ʊ�����������ۣ�
//    stock[1].show();                                  //չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ

    Stock top = stock[0];
    for ( int i = 1; i < SIZE; i++ )
        top = top.topval( stock[i] );
    std::cout << "\nMost valuable holding: \n";
    top.show();

    std::cout << "Done.\n";

    return 0;
}
