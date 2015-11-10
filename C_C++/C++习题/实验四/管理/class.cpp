#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40;

class Person {
    private :
        int age;
        char name[MAXN];
    public :
        Person(){ age = 0; strcpy( name, "unnamed" ); };
        Person( int a, char * n ){
            age = a;
            strcpy( name, n );
        };
        ~Person(){};
        void Output(){
            printf("Age: %d\n", age );
            printf("Name: %s\n", name );
        };
} ;

class Student : public Person {
    private :
        char Profession[MAXN];
    public :
        ~Student(){};
        Student();
        Student( int , char * , char * );
        void Output();
} ;
Student::Student() : Person()
{
    strcpy( Profession, "нч" );
    return ;
}
Student::Student( int a, char * n, char * p ) : Person( a, n )
{
    strcpy( Profession, p );
    return ;
}
void Student::Output()
{
    Person::Output();
    printf("Profession: %s\n", Profession );
    return ;
}

class Teacher : public Person {
    private :
        char Profession[MAXN];
    public :
        ~Teacher(){};
        Teacher();
        Teacher( int , char * , char * );
        void Output();
} ;
Teacher::Teacher() : Person()
{
    strcpy( Profession, "нч" );
    return ;
}
Teacher::Teacher( int a, char * n, char * c ) : Person( a, n )
{
    strcpy( Profession, c );
    return ;
}
void Teacher::Output()
{
    Person::Output();
    printf("Profession: %s\n", Profession );
    return ;
}

class empolyee1 : public Teacher {
    private :
        char Profession[MAXN];
    public :
        ~empolyee1(){};
        empolyee1();
        empolyee1( int , char * , char * , char * );
        void Output();
};
empolyee1::empolyee1() : Teacher()
{
    strcpy( Profession, "Teacher" );
    return ;
}
empolyee1::empolyee1( int a, char * n, char * p, char * t ) : Teacher( a, n, p )
{
    strcpy( Profession, t );
    return ;
}
void empolyee1::Output()
{
    Teacher::Output();
    printf("Another Profession: %s\n", Profession );
    return ;
}

class empolyee2: public Teacher, public Student {
    private :
        char Profession[MAXN];
    public :
        ~empolyee2(){};
        empolyee2();
        empolyee2( int , char * , char * , char *, char * );
        void Output();
};
empolyee2::empolyee2() : Teacher()
{
    strcpy( Profession, "Teacher" );
    return ;
}
empolyee2::empolyee2( int a, char * n, char * p, char * t, char * s ) : Teacher( a, n, p ), Student( a, n, t )
{
    strcpy( Profession, s );
    return ;
}
void empolyee2::Output()
{
    Teacher::Output();
    printf("Another ID:\n");
    Student::Output();
    printf("Another Profession: %s\n", Profession );
    return ;
}
