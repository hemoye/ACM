#include <cstdio>
#include <cmath>
using namespace std;

class Triangle {
    private :
        int a;
        int b;
        int c;
        float area;
    public :
        Triangle( int , int , int );
        ~Triangle(){
            printf("Triangle %d %d %d ���ͷ�\n", a, b, c );
        }
        void print( void );
} ;
Triangle::Triangle( int x, int y, int z )
{
    printf("�в����Ĺ��캯��������\n");
    a = x;
    b = y;
    c = z;
    return ;
}
void Triangle::print( void )
{
    float p = ( a + b + c ) / 2;
    area = sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
    printf("�����ε������: %.3f\n", area );
    return ;
}
