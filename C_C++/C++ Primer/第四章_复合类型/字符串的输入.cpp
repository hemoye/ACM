#include <iostream>
#include <cstring>

int main( void )
{
    using namespace std;

    const int MAX = 4;
    char name[MAX];

    cout << "Please input your name:";
    cin  >> name;
    cout << name << ". Are you sure?" << endl;
    cout << "Your name have " << strlen( name ) << " bytes." << endl;
    cout << "But the array just have " << sizeof( name ) << " bytes.\n";

    return 0;
}
/**
    �ܽ᣺
        ��C���Ե��������ƣ�C++��cin�ھ����ַ���ʱ
        ���ܽ��յ��ո����ܹ��������鳤�Ƚ��ա�
**/
