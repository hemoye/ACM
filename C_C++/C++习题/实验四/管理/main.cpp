#include <cstdio>
#include <iostream>
#include "class.cpp"
using namespace std;

int main( int agrc, char *agrv[] )
{
    Student stud( 18, "hemoye", "ѧ��" );
    stud.Output();
    puts("");
    Teacher teach( 27, "hemoye", "��ʦ" );
    teach.Output();
    puts("");
    empolyee1 e1( 18, "hemoye", "ѧ��", "��Ա" );
    e1.Output();
    puts("");
    empolyee2 e2( 26, "hemoye", "ѧ��", "��ʦ", "��Ա" );
    e2.Output();
    puts("");

    return 0;
}
