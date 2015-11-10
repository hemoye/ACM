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

    total = coding.Sum( fixing );
    cout << "coding.Sum( fixing ) = ";
    total.Show();
    cout << endl;

    cout << "Done.\n";

    return 0;
}
