#include <iostream>
#define  MAX 10

typedef struct
{
    int age;
    char name[MAX];
    char sex[MAX];
} STUDENT;

int main( void )
{
    using namespace std;

    STUDENT * student = new STUDENT;

    cout << "����������:";
    cin  >> student->age;
    cout << "����������:";
    cin  >> student->name;
    cout << "�������Ա�:";
    cin  >> student->sex;

    cout << student->name << endl << student->age << endl << student->sex << endl;

    delete student;

    return 0;
}
