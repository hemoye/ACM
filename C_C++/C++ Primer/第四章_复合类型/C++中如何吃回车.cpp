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
    总结：在C++中吃回车有两种方法：
    一是靠在cin输入完成后加如一个
    后缀.get()来丢弃回车符
    二是靠在输入完成之后另起一行
    用cin.get()来丢弃回车符
**/
