#include <iostream>

int main( void )
{
    using namespace std;

    char ch;

    cout << "c) carni vore." << "\t\t"
         << "p) pianist." << endl
         << "t) tree." << "\t\t"
         << "g) game" << endl;

    cin.get( ch ).get();

    while ( ch != 'c' && ch != 'p' && ch != 't' && ch != 'g' )
    {
        cout << "Please enter a a. p. t. or g: ";
        cin.get( ch ).get();
    }
    cout << "A maple is a tree.\n";

    return 0;
}
