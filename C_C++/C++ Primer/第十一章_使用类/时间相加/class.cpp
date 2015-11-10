#include <iostream>
#define  TIME 60

class Time
{
private :
    int hours;
    int minutes;
public :
    Time();
    ~Time();
    Time( int h, int m = 0 );
    void AddMin( int m );
    void AddHr( int h );
    void Reset( int h = 0, int m = 0 );
    Time & Sum( const Time & t )const;
    void Show()const;
};

Time::Time()
{
    hours = minutes = 0;
}
Time::~Time()
{
    using std::cout;
    using std::endl;

    cout << "Bye~bye" << endl;
}
Time::Time( int h, int m )
{
    hours = h;
    minutes = m;
}
void Time::AddMin( int m )
{
    minutes += m;
    hours += minutes / TIME;
    minutes %= TIME;

    return ;
}
void Time::AddHr( int h )
{
    hours += h;

    return ;
}
void Time::Reset( int h, int m )
{
    hours = h;
    minutes = m;

    return ;
}
Time & Time::Sum( const Time & t )const
{
    Time sum;

    sum.minutes = t.minutes + minutes;
    sum.hours = hours + t.hours + sum.minutes / TIME;
    sum.minutes %= TIME;

    return sum;
}
void Time::Show()const
{
    std::cout << hours << " hours. " << minutes << " minutes.";
    std::cout << std::endl;
}
