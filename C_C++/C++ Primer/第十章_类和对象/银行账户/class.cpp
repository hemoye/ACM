#include <iostream>
#define  MAX 20

class Stock                                             //������
{
private :                                               //˽�г�Ա
    char name[MAX];     //�û���
    char num[MAX];      //���п���
    double money;       //�������Ǯ
public :                                                //���ó�Ա
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
/**********����**********/
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

/**********��Ǯ*********/
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
/*********ȡǮ**********/
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
/**********չʾ**********/
void Stock::show()
{
    using std::cout;
    using std::endl;

    cout << "Name: " << name << endl;
    cout << "Number: "<< num << endl;
    cout << "Money: $" << money << endl << endl;

    return ;
}
