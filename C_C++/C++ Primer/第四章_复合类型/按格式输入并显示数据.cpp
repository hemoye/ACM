#include <iostream>
#include <string>

int main( void )
{
    using namespace std;

    const int MAX = 24;

    char str1[MAX], str2[MAX];
    char ch;
    int age;

    cout << "What is your first name?";
    cin.get( str1, MAX ).get();
    cout << "What is your last name?";
    cin.get( str2, MAX ).get();
    cout << "What letter grade do you deserve?";
    cin  >> ch;
    cout << "What is your age?";
    cin  >> age;
    cout << "Name: " << str1 << ", " << str2 << endl;
    ch += 1;
    cout << "Gread: " << ch << endl;
    cout << "Age: " << age << endl;

    return 0;
}
