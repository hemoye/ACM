#include <iostream>
#include <cstring>

int main( void )
{
    using namespace std;

    const int SIZE = 24;

    char name[SIZE];

    cout << "Now, Please input your name: ";
    cin  >> name;
    cout << "The array have " << sizeof( name ) << " letters." << endl;
    cout << "Ok, " << name << "! Your name have " << strlen( name ) << " bytes.\n";

    return 0;
}
/**
�������룺
        hemoxie
���������
        Now, Please input your name: hemoxie
        The array have 24 letters.
        Ok, hemoxie! Your name have 7 bytes.
**/
/****
�ܽ᣺
     strlen������������ʵ�ʳ���
     sizeof������������ѱ������
     �ڴ���ܳ���
****/
