#include <iostream>

using namespace std;

void Polish( string &, string & );

int main( void )
{
    string in, post;

    while ( cin >> in ){                    /**输入中缀表达式**/
        Polish( in, post );
    }

    return 0;
}
void Polish( string & in, string & post )
{
    string stack;                           /**模拟运算栈**/
    int top( 0 );                           /**栈顶指针**/
    int len = in.length();                  /**取得中缀表达式的长度**/
    int i, j;

    for ( i = 0, j = 0; i < len; i++ ){
        if ( '0' <= in[i] && in[i] <= '9' || 'a' <= in[i] && in[i] <= 'z' ){        /**数据部分直接存进后缀表达式**/
            post[j++] = in[i];
        }
        else if ( '(' == in[i] || '*' == in[i] || '/' == in[i] ){                   /**如果是（、*、/则直接进栈**/
            stack[++top] = in[i];
        }
        else if ( ')' == in[i] ){                                                   /**如果是右括号则出栈至左括号**/
            while ( stack[top] != '(' && top ){
                post[j++] = stack[top];
                top--;
            }
            top--;
        }
        else if ( '-' == in[i] || '+' == in[i] ){                                   /**如果是+、-则判断栈顶运算符优先级是不是低于该运算符**/
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
