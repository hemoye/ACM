#include <iostream>
#define  MAX 40

class Stock                                             //������
{
private :                                               //˽�г�Ա
    char company[MAX];
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val;}
public :                                                //���ó�Ա
    Stock();
    ~Stock();
    Stock( const char * co, int n = 0, double pr = 0 );
    void buy( int num, double price );
    void sell( int num, double price );
    void update( double price );
    void show();
} ;
Stock::Stock()
{
    std::cout << "Default constructor called.\n";
    std::strcpy( company, "no name" );
    shares = 0;
    share_val = 0;
    total_val = 0;
}
Stock::~Stock()
{
    std::cout << "Bye, " << company << std::endl;
    return ;
}
/**********¼���Ʊ����**********/
Stock::Stock( const char * co, int n, double pr )
{
    std::strncpy( company, co, 39 );
    company[39] = '\0';

    if ( n < 0 )
    {
        std::cout << "Number of shares can't be negative."
                  << company << " shares set to zero.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();

    return ;
}

/**********�����Ʊ**********/
void Stock::buy( int num, double price )
{
    if ( num < 0 )
    {
        std::cout << "Number of shares purchsaed can't be negative."
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
/**********������Ʊ**********/
void Stock::sell( int num, double price )
{
    if ( num < 0 )
    {
        std::cout << "Number of shares purchsaed can't be negative."
                  << "Transaction is aborted.\n";
    }
    else if ( num > shares )
    {
        std::cout << "You can't sell more than you have! "
                  << "Transaction is aborted.\n";
    }
    else
    {
        std::cout << "After selled, the information as follow:" << std::endl;
        shares -= num;
        share_val = price;
        set_tot();
    }

    return ;
}
/**********���¹�Ʊ����**********/
void Stock::update( double price )
{
    share_val = price;
    set_tot();
    std::cout << "After update, the information as follow:" << std::endl;

    return ;
}
/**********չʾ��Ʊ����**********/
void Stock::show()
{
    using std::cout;
    using std::endl;

    cout << "Company: " << company << endl;
    cout << "Shares: "<< shares << endl;
    cout << "Share Price: $" << share_val << endl;
    cout << "Total Worth: $" << total_val << endl << endl;

    return ;
}
