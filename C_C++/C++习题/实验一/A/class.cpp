#include <cstdio>
#include <algorithm>
using namespace std;

class A {
    private :
        char data;
    public :
        A();
        ~A(){
            printf("%c����\n", data );
        }
} ;
A::A()
{
    printf("�޲����Ĺ��캯��������\n");
    data = 'x';
}
