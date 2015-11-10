#include <cstdio>
#include <algorithm>
using namespace std;

class A {
    private :
        char data;
    public :
        A();
        ~A(){
            printf("%c被释\n", data );
        }
} ;
A::A()
{
    printf("无参数的构造函数被调用\n");
    data = 'x';
}
