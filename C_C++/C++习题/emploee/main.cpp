#include <iostream>
#include <cstring>

using namespace std;
class emploee
{
    public:
      emploee();
      ~emploee();
      void set(char a[], char b[], char c[], char d[], char e[]);
      void changeAddress(char *f );
      void output();
    private:
       char name[10];
       char address[20];
       char city[10];
       char province[10];
       char *postalcode;
};
emploee::emploee()
{
   cout<<"none"<<endl;
}
emploee::~emploee()
{
   delete []  postalcode;
}
void emploee::set(char a[], char b[], char c[], char d[], char e[])
{
    strcpy(name, a);
    strcpy(address, b);
    strcpy(city, c);
    strcpy(province, d);
    postalcode= new char[10];
    strcpy(postalcode, e);
}
void emploee::changeAddress(char *f)
{
    strcpy(address, f);
}
void emploee::output()
{
    cout<<name<<endl<<address<<endl<<city<<endl<<province<<endl<<postalcode<<endl;
}
int main()
{
    emploee P;
    P.set("nvwang","cp","tokyo","117","heat");
    P.output();
    P.changeAddress("telepoter");
    P.output();
}
