//#include <iostream>
//
//using namespace std;
//
//int main( void )
//{
//    string str;
//    int n;
//
//    cin >> n;
//    while ( n-- ){
//        cin >> str;
//        int len = str.length();
//        int count( 1 );
//        if ( 1 == len ){
//            count += str[0] - 'a';
//        }
//        else {
//            for ( int i = 1; i < len; i++ ){
//                count = count * ( str[i-1] - 'a' + 1 )
//            }
//        }
//    }
//
//    return 0;
//}
#include <iostream>
#include <cstring>
using namespace std;
int C(int r,int n)
{
    int anwser=1;
    int a=1,b=1;
    if(r!=0)
    {
        for(int i=n; i>n-r; i--)
        {
            a*=i;
        }
        for(int j=2; j<=r; j++)
            b*=j;
        anwser=a/b;
    }
    return anwser;
}
int main ()
{
    int i,j;
    char ch[10];
    int ch1[10];
    cin>>ch;
    int n=strlen(ch);
    int sum=1;
    int start=1;
    for(i=1; i<n; i++)
        sum+=C(i,26);
    for(i=0; i<n; i++)
        ch1[i]=ch[i]-96;
    for(i=n; i>=1; i--)
    {
        for(j=start; j<ch1[n-i]; j++)
        {
            sum+=C(i-1,26-j);
        }
        start=ch1[n-i]+1;
    }
    cout<<sum<<endl;
    return 0;
}
