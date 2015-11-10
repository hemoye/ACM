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

    cout << "请输入年龄:";
    cin  >> student->age;
    cout << "请输入姓名:";
    cin  >> student->name;
    cout << "请输入性别:";
    cin  >> student->sex;

    cout << student->name << endl << student->age << endl << student->sex << endl;

    delete student;

    return 0;
}
