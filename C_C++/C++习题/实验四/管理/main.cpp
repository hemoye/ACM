#include <cstdio>
#include <iostream>
#include "class.cpp"
using namespace std;

int main( int agrc, char *agrv[] )
{
    Student stud( 18, "hemoye", "学生" );
    stud.Output();
    puts("");
    Teacher teach( 27, "hemoye", "老师" );
    teach.Output();
    puts("");
    empolyee1 e1( 18, "hemoye", "学生", "雇员" );
    e1.Output();
    puts("");
    empolyee2 e2( 26, "hemoye", "学生", "老师", "雇员" );
    e2.Output();
    puts("");

    return 0;
}
