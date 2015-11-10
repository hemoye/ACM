#include <iostream>
#include "CAnimal.cpp"
using namespace std;

int main( int agrc, char *agrv[] )
{
    Chrose c;
    c.Input( "Chrose", 1, 2, 3, 4 );
    c.Output();

    return 0;
}
