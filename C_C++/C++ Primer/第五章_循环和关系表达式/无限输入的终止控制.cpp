#include <iostream>

int main( void )
{
    using namespace std;

    char ch;
    int count = 0;

    cin.get( ch );
    /**
    第一种方式
        while ( cin.eof() == 0 )                    //和cin.fail()一样都是检查文件是否已到达末尾，如果不是末尾则返回假，如果是文件末尾则返回真
        {
            cout << ch;
            ++count;
            cin.get( ch );
        }
    **/
    /**
    第二种方式
        while ( cin.get( ch ) )
        {
            cout << ch;
            count++;
        }
    **/
    /**
    第三种方式
        while ( ( cin.get( ch ) ) )
        {
            cout << ch;
            count++;
        }
    **/
    while ( cin.get( ch ) )
    {
        cout << ch;
        count++;
    }
    count--;
    cout << count << " character read." << endl;

    return 0;
}
