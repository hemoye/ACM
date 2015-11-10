#include <iostream>

using namespace std;

void Polish( string &, string & );

int main( void )
{
    string in, post;

    while ( cin >> in ){                    /**������׺���ʽ**/
        Polish( in, post );
    }

    return 0;
}
void Polish( string & in, string & post )
{
    string stack;                           /**ģ������ջ**/
    int top( 0 );                           /**ջ��ָ��**/
    int len = in.length();                  /**ȡ����׺���ʽ�ĳ���**/
    int i, j;

    for ( i = 0, j = 0; i < len; i++ ){
        if ( '0' <= in[i] && in[i] <= '9' || 'a' <= in[i] && in[i] <= 'z' ){        /**���ݲ���ֱ�Ӵ����׺���ʽ**/
            post[j++] = in[i];
        }
        else if ( '(' == in[i] || '*' == in[i] || '/' == in[i] ){                   /**����ǣ���*��/��ֱ�ӽ�ջ**/
            stack[++top] = in[i];
        }
        else if ( ')' == in[i] ){                                                   /**��������������ջ��������**/
            while ( stack[top] != '(' && top ){
                post[j++] = stack[top];
                top--;
            }
            top--;
        }
        else if ( '-' == in[i] || '+' == in[i] ){                                   /**�����+��-���ж�ջ����������ȼ��ǲ��ǵ��ڸ������**/
            if ( top && '(' != stack[top] ){
                post[j++] = stack[top];
                stack[top] = in[i];
            }
            else {
                stack[++top] = in[i];
            }
        }
    }
    while ( top ){
        post[j++] = stack[top--];
    }
    for ( i = 0; i < j; i++ ){
        cout << post[i] << " ";
    }
    cout << endl;

    return ;
}
