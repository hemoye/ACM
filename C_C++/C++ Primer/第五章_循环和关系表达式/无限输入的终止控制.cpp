#include <iostream>

int main( void )
{
    using namespace std;

    char ch;
    int count = 0;

    cin.get( ch );
    /**
    ��һ�ַ�ʽ
        while ( cin.eof() == 0 )                    //��cin.fail()һ�����Ǽ���ļ��Ƿ��ѵ���ĩβ���������ĩβ�򷵻ؼ٣�������ļ�ĩβ�򷵻���
        {
            cout << ch;
            ++count;
            cin.get( ch );
        }
    **/
    /**
    �ڶ��ַ�ʽ
        while ( cin.get( ch ) )
        {
            cout << ch;
            count++;
        }
    **/
    /**
    �����ַ�ʽ
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
