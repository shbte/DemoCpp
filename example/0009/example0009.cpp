#include <iostream>

using namespace std;

/*
==>
函数没有写而又必须要有返回值时，系统使用默认值，将会导致不可预知的错误
<==
*/
int foo1() {}

bool foo2() {}

int main()
{
    // f001()=814321728
    cout << "f001()=" << foo1() << endl;

    // f002()=64
    cout << "f002()=" << foo2() << endl;

    return 0;
}