#include <iostream>

using namespace std;
double Cude( double );
double ReCude( double & );

int main( void )
{
    double x = 3.0;

    cout << Cude( x );
    cout << " = cube of " << x << endl;
    cout << ReCude( x );
    cout << " = cube of " << x << endl;

    return 0;
}
double Cude( double x )
{
    x = x * x * x;
    return x;
}
double ReCude( double & a )
{
    a = a * a * a;
    return a;
}
/**
    ��codebloks������Ľ���ǣ�
            27 = cube of 3
            27 = cube of 27
    �ܽ�:
        �����ô��ݻ�ı�����ݵ�ֵ
**/
