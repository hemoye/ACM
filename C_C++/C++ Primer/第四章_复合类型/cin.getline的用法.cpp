#include <iostream>

int main( void )
{
    using namespace std;

    const int MAX = 24;
    char name[MAX];
    char data[MAX];

    cout << "Please input your name: ";
    cin >> name;
    //cin.get( name, MAX ).get();
    //cin.get();
    //cin.get( data, MAX ).get();
    cout << name << endl;
    //cout << data << endl;

    return 0;
}
/**
    总结：用cin.get( arrayNAME, arraySIZE ).get()吃掉回车
**/
