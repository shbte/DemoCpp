#include <iostream>

/*
==>
总结下就是，如果ptr代表一个用new申请的内存返回的内存空间地址，即所谓的指针，那么：
    delete ptr -- 代表用来释放内存，且只用来释放ptr指向的内存。
    delete[] rg -- 用来释放rg指向的内存，！！还逐一调用数组中每个对象的 destructor！！

对于像 int/char/long/int* /struct 等等简单数据类型，
由于对象没有 destructor，所以用 delete 和 delete [] 是一样的！但是如果是C++ 对象数组就不同了
<==
*/
void print(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << "a[" << i << "](value)=" << a[i] << ", a[" << i << "](address)=" << &a[i] << std::endl;
    }
    std::cout << std::endl;
}

// 基本类型对象内存释放
void func1()
{
    int *a = new int[10];

    print(a, 10);

    // 针对简单类型 使用 new 分配后的不管是数组还是非数组形式内存空间用两种方式均可
    delete a;
    print(a, 10);

    // delete[] a;
    // print(a, 10);
}

class A
{
private:
    char *m_cBuffer;
    int m_nLen;

public:
    A()
    {
        m_cBuffer = new char[m_nLen];
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
        delete[] m_cBuffer;
    }
};

// 自定义类对象内存释放
void func2()
{
    A *a = new A[10];

    // 仅释放了a指针指向的全部内存空间 但是只调用了a[0]对象的析构函数 剩下的从a[1]到a[9]这9个用户自行分配的m_cBuffer对应内存空间将不能释放 从而造成内存泄漏
    // delete a;

    // 调用使用类对象的析构函数释放用户自己分配内存空间并且   释放了a指针指向的全部内存空间
    delete[] a;
}

int main()
{
    func1();

    func2();

    return 0;
}