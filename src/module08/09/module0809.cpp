#include <iostream>

using namespace std;

/*
==>
单例模式是开发者最常用的设计模式之一
单例模式的应用使得一个类最多只有一个对象
可以将单例模式相关的代码抽象成类模板
需要使用单例模式的类直接使用单例类模式
<==
*/
class Basic
{
private:
    static Basic *pb;
    // 私有化构造函数，防止调用来创建对象
    Basic()
    {
        cout << "Basic::Basic()::this = " << this << endl;
    }
    // 私有化拷贝构造函数，防止调用来创建对象
    Basic(const Basic &obj);
    // 私有化赋值操作符，防止调用来创建对象
    Basic &operator=(const Basic &obj);

public:
    static Basic *NewInstance(); // 不能返回对象，返回对象赋值时，会调用拷贝构造函数，而拷贝构造函数时私有的，无法调用

    void Print()
    {
        cout << "Basic::Print()::this = " << this << endl;
    }

    // ~Basic(); // 单例模式对象贯穿系统整个生命周期，最后由系统销毁
};

// 静态变量赋值
Basic *Basic::pb = NULL;

Basic *Basic::NewInstance()
{
    // 单例模式核心，没有对象时，构建新对象
    if (pb == NULL)
    {
        pb = new Basic();
    }

    return pb;
}

int main()
{
    // NewInstance是静态方法，通过类名进行访问
    Basic *b0 = Basic::NewInstance();
    b0->Print(); // Basic::Print()::this = 0x563bb6e4aeb0

    Basic *b1 = Basic::NewInstance();
    b1->Print(); // Basic::Print()::this = 0x563bb6e4aeb0

    Basic *b2 = Basic::NewInstance();
    b2->Print(); // Basic::Print()::this = 0x563bb6e4aeb0

    return 0;
}