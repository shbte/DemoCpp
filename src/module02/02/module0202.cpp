#include <iostream>

/*
==>
在C语言中，只有一个全局作用域
    C语言中所有的全局标识符共享同一个作用域
    标识符之间可能发生冲突
在C++中提出了命名空间的概念，可以避免全局作用域当中的同名全局变量发生冲突
    命名空间将全局作用域分成不同的部分
    不同命名空间中的标识符可以同名而不会发生冲突
    命名空间可以相互嵌套
    全局作用域也叫默认命名空间
C++命名空间的使用，用于解决名称冲突问题
    使用整个命名空间：using namespace name;
    使用命名空间中的变量：using name::variable;
    使用默认命名空间中的变量：::variable;
<==
*/

namespace first
{
    int i = 1;
    double d = 8.09l;

    namespace second
    {
        int i = 2;
        float f = 2.0f;
    }
}
int main()
{

    using namespace first;
    using namespace second;

    std::cout << "d = " << d << std::endl;
    std::cout << "first::i = " << first::i << std::endl;
    std::cout << "first::second::i = " << first::second::i << std::endl;
    std::cout << "second::i = " << second::i << std::endl;
    std::cout << "f = " << f << std::endl;

    return 0;
}