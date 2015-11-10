#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 40;
using namespace std;

class CAnimal {
    private :
        int age;
        int grow;
        int speed;
        int weight;
    public :
        CAnimal(){ age = grow = speed = weight = 0;};
        ~CAnimal(){};
        void JInput( int , int , int , int );
        void JOutput();
} ;
void CAnimal::JInput( int a, int g, int s, int w )
{
    age = a;
    grow = g;
    speed = s;
    weight = w;
    return ;
}
void CAnimal::JOutput()
{
    printf("Age: %d\n", age );
    printf("grow: %d\n", grow );
    printf("speed: %d\n", speed );
    printf("weight: %d\n", weight );
    return ;
}

class Chrose : public CAnimal {
    private :
        char name[MAXN];
    public :
        Chrose(){ strcpy( name, "####"); };
        ~Chrose(){};
        void Input( char * , int , int , int , int );
        void Output();
} ;
void Chrose::Input( char * n, int a, int g, int s, int w )
{
    strcpy( name, n );
    JInput( a, g, s, w );
    return ;
}
void Chrose::Output()
{
    printf("Kind: %s\n", name );
    JOutput();
}
