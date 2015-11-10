#include <iostream>
#include "class.cpp"

int main( void )
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding( 2, 40 );
    Time fixing( 5, 55 );
    Time total;

    cout << "planing time = ";
    planning.Show();

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time = ";
    fixing.Show();

    //total = coding + fixing;
    total = coding.operator+( fixing );         //上面一种和下面这一种两种表示方法都正确
    cout << "coding.Sum( fixing ) = ";
    total.Show();
    cout << endl;

    cout << "Done.\n";

    return 0;
}
