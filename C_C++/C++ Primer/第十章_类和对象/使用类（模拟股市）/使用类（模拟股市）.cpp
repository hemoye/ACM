#include <iostream>
#include <cstring>
#include "class.cpp"
#define  MAX 40

int main( void )
{
//    Stock stock1;                                   //声明一个Stock类的对象
//    using std::ios_base;

    Stock stock1("NanoSmart", 20, 12.50);         //调用公用函数输入持股信息（公司名称、股数、股价）
/** 格式设置：显示小数点后两位数（包括0）
    std::cout.setf(ios_base::fixed);
    std::cout.precision(2);
    std::cout.setf(ios_base::showpoint);
**/
    stock1.show();                                  /**展示持股人所拥有的股票信息**/
    stock1.buy ( 15, 18.25 );                       /**买进股票（数量、单价）*/
    stock1.show();                                  /**展示持股人所拥有的股票信息*/
    stock1.sell ( 400, 20.00 );                     /**卖出股票（数量、单价）*/
    stock1.show();                                  /**展示持股人所拥有的股票信息*/
    stock1.sell ( 4, 20.00 );                       /**卖出股票（数量、单价）*/
    stock1.show();                                  /**展示持股人所拥有的股票信息*/
    stock1.update( 30 );                            /**更新股票价格*/
    stock1.show();                                  /**展示持股人所拥有的股票信息*/
    std::cout << "Done.\n";

    return 0;
}
