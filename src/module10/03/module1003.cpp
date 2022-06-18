#include <iostream>

using namespace std;

/*
==>
如果异常无法被处理，termainate()结束函数会被自动调用
默认情况下，terminate()调用库函数abort()终止程序
abort()函数使得程序执行异常而立即退出
C++支持替换默认的terminate()函数实现

terminate()函数的替换
    自定义一个无返回值无参数的函数
        不能抛出任何异常
        必须以某种方式结束当前程序
    调用set_terminate()设置自定义的结束函数
        参数类型为void(*)()
        返回值为默认的terminate()函数入口地址

小结：
    如果异常没有被处理，最后terminate()结束整个程序
    terminate()是整个程序释放系统资源的最后机会
    结束函数可以自定义，当不能继续抛出异常
    析构函数中不能抛出异常，可能导致terminate()多次调用

函数抛出的异常不在规格说明中，全局函数unexpected()被调用
默认的unexpected()函数会调用全局terminate()函数
可以自定义函数替换默认的unexpected()函数实现
注意：不是所有的C++编译器都支持这个标准行为

unexpected()函数的替换
    自定义一个无返回值无参数的函数
        能够再次抛出异常
            当异常符合触发函数的异常规格说明时，恢复程序执行
            否则，调用全局terminate()函数结束程序
    调用ser_unexpected()设置自定义的异常函数
        参数类型为void(*)()
        返回值为默认的unexpected()函数入口地址

小结：
    C++中的函数可以声明异常规格说明
    异常规格说明可以看作接口的一部分
    函数抛出的异常不在规格说明中，unexpected()被调用
    unexpected()中能够再次抛出异常
        异常能够匹配，会需程序的执行
        否则，调用terminate()结束程序
<==
*/
void func1() throw()
{

}

int main()
{

    return 0;
}