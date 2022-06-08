#include <iostream>

using namespace std;

/*
==>
运行时的对象退化为结构体的形式
    所有成员变量在内存中依次排布
    成员变量间可能存在内存空隙(内存对齐)
    可以通过内存地址直接访问成员变量(p->i)
    访问权限关键字在运行时失效(编译时有效，编译完后变成二进制就没有访问权限的概念了，可以通过指针和内存地址修改成员变量的值)

类中的成员函数位于代码段中
调用成员函数时对象地址作为参数隐式传递(因为成员函数属于类，不属于对象，函数通过传递过来的this进行区分调用对象)
成员函数通过对象地址访问成员变量
C++语法规则隐藏了对象地址的传递过程(this)

小结：
    C++中的类对象在内存布局上与结构体相同
    成员变量和成员函数在内存中分开存放
    访问权限关键字在运行时失效
    调用成员函数时对象地址作为参数隐式传递
<==
*/
class A
{
    int i;    // 4
    int j;    // 4
    char c;   // 8，因为内存对齐原则，所以这里是8
    double d; // 8
public:
    void print() // 成员变量可能在栈、堆、全局数据区，而成员函数只可能在代码区
    {
        cout << "i=" << i << ", "
             << "j=" << j << ", "
             << "c=" << c << ", "
             << "d=" << d << endl;
    }
};

struct B
{
    int i;    // 4
    int j;    // 4
    char c;   // 8，因为内存对齐原则，所以这里是8
    double d; // 8
};

int main()
{
    A a;
    B b;

    cout << "sizeof(A)=" << sizeof(A) << ", sizeof(a)=" << sizeof(a) << endl;
    cout << "sizeof(B)=" << sizeof(B) << ", sizeof(b)=" << sizeof(b) << endl;

    a.print();
    cout << endl;

    // 重新解释a所占的内存空间，由于A和B在内存空间的排布是一样的，所以可以把a转换成B使用
    B *p = reinterpret_cast<B*>(&a);

    // 私有成员变量(private)失效，可通过指针修改
    p->i = 1;
    p->j = 2;
    p->c = 'c';
    p->d = 3.141592654;

    a.print();
    cout << endl;

    // 再次通过指针修改私有成员变量(private)
    p->i = 100;
    p->j = 200;
    p->c = 'C';
    p->d = 3141.592654;

    // 打印以验证修改
    a.print();

    return 0;
}