#include <iostream>
#include <cstdlib>

using namespace std;

/*
==>
new/delete的本质时C++预定义的操作符
C++对这两个操作符做了严格的行为定义
    new
        1、获取足够的内存空间(默认为堆空间)
        2、在获取的空间中调用构造函数创建对象
    delete
        1、调用析构函数销毁对象
        2、归还对象所占用的空间(默认为堆空间)

在C++中能够重载new/delete操作符
    全局重载(不推荐)
    局部重载(针对具体类进行重载)
重载new/delete的意义在于改变动态对象创建时的内存分配方式

new/delete的重载方式
// static member function
void *operator new (unsigned int size)
{
    void *ret = NULL;

    // ret point to allocated memory

    return ret;
}
// static member function
void operator delete (void *p)
{
    // free the memory which is pointed by p
}

如何在指定的地址上创建C++对象
    在类中重载new/delete操作符
    在new的操作符重载函数中返回指定的地址
    在delete操作符重载中标记对应的地址可用
<==
*/
/* 在全局变量区创建对象 */
class Base
{
private:
    static const int COUNT = 4; // 最大成员数
    static char c_buff[];       // new时所使用的静态空间地址
    static int c_map[];         // 保存地址可用标识符

    int mValue; // sizeof(Base) = 4

public:
    // 重载new函数
    void *operator new(unsigned long size)
    {
        // 返回空间地址值，作为new开辟出的空间地址使用
        void *ret = NULL;

        for (int i = 0; i < COUNT; i++)
        {
            // 标记数组里为0时，说明可用
            if (!c_map[i])
            {
                // 使用c_buff中的空间
                ret = c_buff + i * sizeof(Base);

                // 标记下标i位的地址为不可用
                c_map[i] = 1;

                cout << "Succeed to mallocte memory : " << ret << ", c_buff = " << &c_buff << endl;

                // 空间开辟成功，循环结束
                break;
            }
        }

        return ret;
    }

    // 重载delete函数
    void operator delete(void *p)
    {
        // 将参数指针解释为char类型指针
        char *pc = reinterpret_cast<char *>(p);
        // 获取对象下标
        int index = (pc - c_buff) / sizeof(Base);
        // 用于判断是否为对象的整数倍
        int flag = (pc - c_buff) % sizeof(Base);

        if ((flag == 0) && (0 <= index) && (index < COUNT))
        {
            c_map[index] = 0;

            cout << "Succeed to free memory : " << p << ", c_buff = " << &c_buff << ", index = " << index << endl;
        }
    }
};

// 静态成员变量赋值
char Base::c_buff[sizeof(Base) * Base::COUNT] = {0};
int Base::c_map[Base::COUNT] = {0};

/*
Succeed to mallocte memory : 0x562c774d3160, c_buff = 0x562c774d3160
Succeed to free memory : 0x562c774d3160, c_buff = 0x562c774d3160, index = 0

Succeed to mallocte memory : 0x562c774d3160, c_buff = 0x562c774d3160
pa[0] = 0x562c774d3160
Succeed to mallocte memory : 0x562c774d3164, c_buff = 0x562c774d3160
pa[1] = 0x562c774d3164
Succeed to mallocte memory : 0x562c774d3168, c_buff = 0x562c774d3160
pa[2] = 0x562c774d3168
Succeed to mallocte memory : 0x562c774d316c, c_buff = 0x562c774d3160
pa[3] = 0x562c774d316c
pa[4] = 0
Succeed to free memory : 0x562c774d3160, c_buff = 0x562c774d3160, index = 0
Succeed to free memory : 0x562c774d3164, c_buff = 0x562c774d3160, index = 1
Succeed to free memory : 0x562c774d3168, c_buff = 0x562c774d3160, index = 2
Succeed to free memory : 0x562c774d316c, c_buff = 0x562c774d3160, index = 3
*/
void func1()
{
    Base *pb = new Base;
    delete pb;
    cout << endl;

    Base *pa[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        pa[i] = new Base;
        cout << "pa[" << i << "] = " << pa[i] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        delete pa[i];
    }
}

/* 在栈区创建对象 */
class Basic
{
private:
    // 因为new/delete是静态成员函数，因此，使用了以下的变量也是静态变量
    static int c_count;  // 最大成员数
    static char *c_buff; // new时所使用的空间地址
    static char *c_map;  // 保存地址可用标识符

    int mValue; // sizeof(Base) = 4

public:
    Basic(int i)
    {
        mValue = i;
    }

    ~Basic()
    {
        cout << "Basic::~Basic()" << endl;
    }

    int getValue()
    {
        return mValue;
    }

    static bool setMemory(char *memory, unsigned long size) // 设置为静态成员函数是因为这时对象还没有创建
    {
        bool ret = false;

        // 获取可创建对象数
        c_count = size / sizeof(Basic);
        // 设置标记可用集合，calloc函数将c_cont个char大小的元素设置为0
        c_map = reinterpret_cast<char *>(calloc(c_count, sizeof(char)));

        if (c_count && c_map)
        {
            // 将传入的地址给保存进new是所用的空间地址
            c_buff = memory;

            ret = true;
        }
        else
        {
            free(c_map);
            c_count = 0;
            c_map = NULL;
            c_buff = NULL;
        }

        return ret;
    }

    // 重载new函数
    void *operator new(unsigned long size)
    {
        // 返回空间地址值，作为new开辟出的空间地址使用
        void *ret = NULL;

        if (c_count > 0)
        {
            for (int i = 0; i < c_count; i++)
            {
                // 标记数组里为0时，说明可用
                if (!c_map[i])
                {
                    // 使用c_buff中的空间
                    ret = c_buff + i * sizeof(Base);

                    // 标记下标i位的地址为不可用
                    c_map[i] = 1;

                    cout << "Succeed to mallocte memory : " << ret << ", c_buff = " << reinterpret_cast<void *>(c_buff) << endl;

                    // 空间开辟成功，循环结束
                    break;
                }
            }
        }
        else
        {
            ret = malloc(size);
            cout << "malloc to ret = " << ret << endl;
        }

        return ret;
    }

    // 重载delete函数
    void operator delete(void *p)
    {
        if (c_count > 0)
        {
            // 将参数指针解释为char类型指针
            char *pc = reinterpret_cast<char *>(p);
            // 获取对象下标
            int index = (pc - c_buff) / sizeof(Base);
            // 用于判断是否为对象的整数倍
            int flag = (pc - c_buff) % sizeof(Base);

            if ((flag == 0) && (0 <= index) && (index < c_count))
            {
                c_map[index] = 0;

                cout << "Succeed to free memory : " << p << ", c_buff = " << reinterpret_cast<void *>(c_buff) << ", index = " << index << endl;
            }
        }
        else
        {
            cout << "free to p  = " << p << endl;
            free(p);
        }
    }
};

int Basic::c_count = 0;
char *Basic::c_buff = NULL;
char *Basic::c_map = NULL;

/*
malloc to ret = 0x560f8e9e4eb0
Basic::~Basic()
free to p  = 0x560f8e9e4eb0

Succeed to mallocte memory : 0x7ffec4150610, c_buff = 0x7ffec4150610
pa[0] = 0x7ffec4150610, pa[0].mValue = 0
Succeed to mallocte memory : 0x7ffec4150614, c_buff = 0x7ffec4150610
pa[1] = 0x7ffec4150614, pa[1].mValue = 1
Succeed to mallocte memory : 0x7ffec4150618, c_buff = 0x7ffec4150610
pa[2] = 0x7ffec4150618, pa[2].mValue = 2
Succeed to mallocte memory : 0x7ffec415061c, c_buff = 0x7ffec4150610
pa[3] = 0x7ffec415061c, pa[3].mValue = 3
Succeed to mallocte memory : 0x7ffec4150620, c_buff = 0x7ffec4150610
pa[4] = 0x7ffec4150620, pa[4].mValue = 4
Basic::~Basic()
Succeed to free memory : 0x7ffec4150610, c_buff = 0x7ffec4150610, index = 0
Basic::~Basic()
Succeed to free memory : 0x7ffec4150614, c_buff = 0x7ffec4150610, index = 1
Basic::~Basic()
Succeed to free memory : 0x7ffec4150618, c_buff = 0x7ffec4150610, index = 2
Basic::~Basic()
Succeed to free memory : 0x7ffec415061c, c_buff = 0x7ffec4150610, index = 3
Basic::~Basic()
Succeed to free memory : 0x7ffec4150620, c_buff = 0x7ffec4150610, index = 4
*/
void func2()
{
    Basic *pb = new Basic(10);
    delete pb;
    cout << endl;

    // 由于a的大小为12,Basic的为4,因此，只能创建3个对象
    // char a[12] = {0};
    char a[20] = {0};
    Basic::setMemory(a, sizeof(a));
    Basic *pa[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        pa[i] = new Basic(i);
        cout << "pa[" << i << "] = " << pa[i] << ", pa[" << i << "].mValue = " << pa[i]->getValue() << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        delete pa[i];
    }
}

int main()
{
    // 在全局区创建对象
    // func1();

    // 在栈区创建对象
    func2();

    return 0;
}