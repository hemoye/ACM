#include <iostream>

int main( void )
{
    using namespace std;

    const int MAX = 20;
    char name[MAX];
    char data[MAX];
    int  year;

    cin.get( name, MAX ).get();
    cin.get( data, MAX ).get();
    cout << name << endl << data << endl;
    cin.getline( name, MAX );
    (cin  >> year).get();
    cin.getline( data, MAX );
    cout << name << endl << data << endl;

    return 0;
}
/**
    �ܽ᣺��C++�гԻس������ַ�����
    һ�ǿ���cin������ɺ����һ��
    ��׺.get()�������س���
    ���ǿ����������֮������һ��
    ��cin.get()�������س���
**/
