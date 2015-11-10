#include <iostream>

int main( void )
{
    using namespace std;
    int * ptr = new int;                    //动态分配一个整型数据的内存
    int * q = new int [4];                  //动态分配4个连续的双精度数据的内存

    *ptr = 4;
    *(q + 1) = 1;
    *q = 0;
    q[2] = 2;
    q[3] = 3;

    cout << *ptr << " located " << ptr << endl;
    cout << q[0] << q[1] << q[2] << q[3] << endl;

    delete ptr;
    delete [] q;

    return 0;
}
