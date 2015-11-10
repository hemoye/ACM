#include <iostream>
#define  MAX 20

class Stock                                             //构建类
{
private :                                               //私有成员
    char name[MAX];     //用户名
    char num[MAX];      //银行卡号
    double money;       //银行里的钱
public :                                                //公用成员
    Stock();
    ~Stock();
    Stock( const char * co, char * n, double pr );
    void draw( double number );
    void memory( double number );
    void show();
} ;
Stock::Stock()
{
    std::cout << "Default constructor called.\n";
    std::strcpy( name, "no name" );
    std::strcpy( num, "0000000000000000000" );
    money = 0;
}
Stock::~Stock()
{
    std::cout << "Bye, " << name << std::endl;
    return ;
}
/**********开户**********/
Stock::Stock( const char * co, char * n, double pr )
{
    std::strncpy( name, co, 19 );
    name[19] = '\0';
    std::strncpy( num, n, 19 );
    num[19] = '\0';

    if ( pr < 0 )
    {
        std::cout << "Number of money can't be negative."
                  << name << " money set to zero.\n";
        money = 0;
    }
    else
        money = pr;

    return ;
}

/**********存钱*********/
void Stock::memory( double number )
{
    if ( number < 0 )
    {
        std::cout << "Number of money purchsaed can't be negative."
                  << "Transaction is aborted.\n";
    }
    else
        money += number;

    return ;
}
/*********取钱**********/
void Stock::draw( double number )
{
    if ( number < 0 )
    {
        std::cout << "Number of money purchsaed can't be negative."
                  << "Transaction is aborted.\n";
    }
    else if ( number > money )
    {
        std::cout << "You can't draw more than you have! "
                  << "Transaction is aborted.\n";
    }
    else
    {
        std::cout << "After selled, the information as follow:" << std::endl;
        money -= number;
    }

    return ;
}
/**********展示**********/
void Stock::show()
{
    using std::cout;
    using std::endl;

    cout << "Name: " << name << endl;
    cout << "Number: "<< num << endl;
    cout << "Money: $" << money << endl << endl;

    return ;
}
