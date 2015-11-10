#include <iostream>

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

using namespace std;
void Output( struct box );
void Count( struct box * );

int main( void )
{
    struct box temp;

    cin >> temp.height >> temp.width >> temp.length;
    Output( temp );
    Count( &temp );
    Output( temp );

    return 0;
}
void Output( struct box temp )
{
    cout << temp.height << temp.width << temp.length << endl;
    cout << temp.volume << endl;

    return ;
}
void Count( struct box * p )
{
    p->volume = p->height * p->width * p->length;
    return ;
}
