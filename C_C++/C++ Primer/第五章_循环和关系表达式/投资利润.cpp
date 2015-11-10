#include <iostream>

int main( void )
{
    using namespace std;
    float sum_Daphe = 100, sum_Cleo = 100;
    int year = 0;

    while ( sum_Cleo <= sum_Daphe )
    {
        year++;
        sum_Daphe += 10;
        sum_Cleo += sum_Cleo * 0.05;
    }
    cout << year << endl;

    return 0;
}
