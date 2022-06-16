#include <iostream>

using namespace std;

/*
==>
new[]/delete[]与new/delete完全不同
    动态对象数组创建通过new[]完成
    动态对象数组的销毁通过delete[]完成
    new[]/delete[]也能够被重载，进而改变内存管理方式

new[]/delete[]的重载方式
// static member function
void *operator new[](unsigned long size)
{
    return malloc(size);
}
//static member function
void operator delete[](void *p)
{
    free(p);
}

注意事项
    new[]实际需要返回的内存空间可能比期望的要多
    对象数组占用的内存中需要保存数组信息
    数组信息用于确定构造函数和析构函数的调用次数

小结：
    new/delete的本质为操作符
    可以通过全局函数重载new/delete(不推荐)
    可以针对具体的类重载new/delete
    new[]/delete[]与new/delete完全不同
    new[]/delete[]也是可以被重载的操作符
    new[]返回的内存空间可能比期望的要多
<==
*/
class Base
{
private:
    int mi;

public:
    Base()
    {
        mi = 0;
    }

    void *operator new(unsigned long size)
    {
        cout << "operator new(unsigned long size)::size = " << size << endl;
        void *ret = NULL;

        ret = malloc(size);

        return ret;
    }
    void *operator new[](unsigned long size)
    {
        cout << "operator new[](unsigned long size)::size = " << size << endl;
        void *ret = NULL;

        ret = malloc(size);

        return ret;
    }

    void operator delete(void *p)
    {
        cout << "operator delete(void *p)::p = " << p << endl;
        free(p);
    }
    void operator delete[](void *p)
    {
        cout << "operator delete[](void *p)::p = " << p << endl;
        free(p);
    }

    ~Base() {}
};

int main()
{

    Base *pb = new Base; // operator new(unsigned long size)::size = 4
    delete pb;           // operator delete(void *p)::p = 0x55d3aa9d72c0

    // 数组的实际大小>sizeof(Base) * n，多出来的有一部分用于存储数组元素个数n
    Base *pa = new Base[1]; // operator new[](unsigned long size)::size = 12
    delete[] pa;            // operator delete[](void *p)::p = 0x55d3aa9d72c0

    return 0;
}