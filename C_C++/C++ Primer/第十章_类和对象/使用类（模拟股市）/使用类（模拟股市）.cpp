#include <iostream>
#include <cstring>
#include "class.cpp"
#define  MAX 40

int main( void )
{
//    Stock stock1;                                   //����һ��Stock��Ķ���
//    using std::ios_base;

    Stock stock1("NanoSmart", 20, 12.50);         //���ù��ú�������ֹ���Ϣ����˾���ơ��������ɼۣ�
/** ��ʽ���ã���ʾС�������λ��������0��
    std::cout.setf(ios_base::fixed);
    std::cout.precision(2);
    std::cout.setf(ios_base::showpoint);
**/
    stock1.show();                                  /**չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ**/
    stock1.buy ( 15, 18.25 );                       /**�����Ʊ�����������ۣ�*/
    stock1.show();                                  /**չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ*/
    stock1.sell ( 400, 20.00 );                     /**������Ʊ�����������ۣ�*/
    stock1.show();                                  /**չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ*/
    stock1.sell ( 4, 20.00 );                       /**������Ʊ�����������ۣ�*/
    stock1.show();                                  /**չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ*/
    stock1.update( 30 );                            /**���¹�Ʊ�۸�*/
    stock1.show();                                  /**չʾ�ֹ�����ӵ�еĹ�Ʊ��Ϣ*/
    std::cout << "Done.\n";

    return 0;
}
