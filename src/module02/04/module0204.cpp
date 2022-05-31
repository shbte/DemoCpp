#include <iostream>

/*
==>
const常量的判别准则
    只有用字面量初始化的const常量才会进入符号表
    使用其它变量初始化的const常量依然是只读变量
    被volatile修饰的const常量不会进入符号表
在编译期间不能直接确定初始值的const标识符，都被作为只读变量处理

<==
*/
int main()
{


    return  0;
}