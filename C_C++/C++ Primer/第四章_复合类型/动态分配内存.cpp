#include <iostream>

int main( void )
{
    using namespace std;
    int * ptr = new int;                    //��̬����һ���������ݵ��ڴ�
    int * q = new int [4];                  //��̬����4��������˫�������ݵ��ڴ�

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
