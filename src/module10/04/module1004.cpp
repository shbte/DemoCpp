#include <iostream>

using namespace std;

/*
==>
动态内存申请
    malloc函数申请失败时返回NULL值
    new关键字申请失败时(根据编译器的不同)
        返回NULL值
        抛出std::bad_alloc异常

new关键字在C++规范中的标准行为
    在堆空间申请足够大的内存
        成功：
            在获取的空间中调用构造函数创建对象
            返回对象的地址
        失败：
            抛出std::bad_alloc异常
    new在分配内存时
        如果空间不足，会调用全局的new_handler()函数
        new_handler()函数中抛出std::bad_alloc异常
    可以自定义new_handler()函数
        处理默认的new内存分配失败的情况

解决方案：
    全局范围(不推荐)
        重新定义new/delete的实现，不抛出任何异常
        自定义new_handler()函数，不抛出任何异常
    类层次范围
        重载new/delete，不抛出任何异常
    单次动态内存分配
        使用nothrow参数，指明new不抛出异常
结论：
    不是所有的编译器都遵循C++的标准规范
    编译器可能重定义new的实现，并在实现中抛出bad_alloc异常
    编译器的默认实现中，可能没有设置全局的new_handler()函数
    对于移植性要求较高的代码，需要考虑new的具体细节

小结：
    不同的编译器在动态内存分配上的实现细节不同
    malloc函数在内存申请失败时返回NULL值
    new关键字在内存申请失败时
        可能返回NULL值
        可能抛出bad_alloc异常
<==
*/
void func1()
{
    int a[2] = {0};
    cout << "a0 = " << a[0] << ", a1 = " << a[1] << ", a = " << a << endl;

    struct Demo
    {
        int x;
        int y;
    };

    Demo *pd = new (a) Demo(); // 利用a的空间，在空间a上面创建Demo对象

    pd->x = 1;
    pd->y = 2;

    cout << "x = " << pd->x << ", y = " << pd->y << endl;
    cout << "a = " << a << ", pd = " << pd << endl;

    pd->~Demo(); // 显式调用析构函数，就算不显式调用，也会隐式调用
    // delete pd; // double free or corruption (out)，因为上面会隐式调用析构函数
}

class Base
{
private:
    int mi;

public:
    Base()
    {
        cout << "Base::Base()" << endl;

        mi = 1; // 段错误 (核心已转储)：因为new失败，返回NULL，在空间NULL进行复制操作，因此失败
        cout << "mi = " << mi << ", this = " << this << endl;
    }

    // 重载new函数，返回NULL
    void *operator new(unsigned long size) throw() // throw()可以让该函数不抛出异常
    {
        cout << "operator new(unsigned long size)" << endl;

        return NULL;
    }

    void operator delete(void *p)
    {
        cout << "operator delete(void *p)" << endl;

        free(p);
    }
};
// new开辟空间失败时(返回NULL)，构造函数赋值时失败
void func2()
{
    Base *pb = new Base();

    cout << "pb = " << pb << endl;

    delete pb;
}

int main()
{
    // func1();

    func2();

    return 0;
}