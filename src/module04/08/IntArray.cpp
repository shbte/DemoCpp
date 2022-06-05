#include <iostream>

#include "IntArray.h"

IntArray::IntArray(int len)
{
    std::cout << "=> IntArray(int len)::len=" << len << std::endl;

    m_length = len;
}

bool IntArray::construct()
{
    std::cout << "=> construct()" << std::endl;

    bool ret = false;
    m_pointer = new int[m_length];

    for (int i = 0; i < m_length; i++)
    {
        m_pointer[i] = i;
    }

    ret = true;

    return ret;
}

// 利用二阶构造创建新对象，私有构造函数(防止构造过程中失败，而返回半成品)
IntArray &IntArray::NewInstance(int len)
{
    std::cout << "=> NewInstance(int len)" << std::endl;

    IntArray *ret = NULL;

    // 创建新对象，同时为IntArray对象的m_length赋值
    ret = new IntArray(len);

    // construct为IntArray对象的m_pointer赋值
    // 当创建失败或者赋值失败时，释放新开辟的空间
    if (!(ret && (ret->construct())))
    {
        delete ret;
        ret = NULL;
    }

    return *ret; // 返回对象，尽量避免指针操作
}

// 深拷贝实现(重载拷贝构造函数)
IntArray::IntArray(const IntArray &obj)
{
    std::cout << "=> IntArray(const IntArray &obj)" << std::endl;

    m_length = obj.m_length;
    m_pointer = new int[obj.m_length];

    for (int i = 0; i < obj.m_length; i++)
    {
        m_pointer[i] = obj.m_pointer[i];
    }
}

// 深拷贝实现(重载赋值操作符)
IntArray &IntArray::operator=(const IntArray &obj)
{
    std::cout << "=> &IntArray::operator=(const IntArray &obj)" << std::endl;

    // 判断是否是自拷贝，自拷贝时返回原对象
    if (this != &obj)
    {
        int *tmp = new int[obj.m_length];

        for (int i = 0; i < obj.m_length; i++)
        {
            tmp[i] = obj.m_pointer[i];
        }

        // 释放原指向的内存地址，防止内存溢出
        delete[] this->m_pointer;

        // 为this对象赋值
        this->m_length = obj.m_length;
        this->m_pointer = tmp;
    }

    return *this;
}

// 获取数组长度
int IntArray::getLength()
{
    return m_length;
}

// 获取数组下标为index的值
bool IntArray::getValue(int index, int &value)
{
    std::cout << "=> getValue(" << index << ")" << std::endl;

    bool ret = (0 <= index) && (index < getLength());

    if (ret)
    {
        value = m_pointer[index];
    }

    return ret;
}

// 设置数组下标为index的值为value
bool IntArray::setVaule(int index, int value)
{
    std::cout << "=> setVaule(" << index << ", " << value << ")" << std::endl;

    bool ret = (0 <= index) && (index < m_length);

    if (ret)
    {
        m_pointer[index] = value;
    }

    return ret;
}

// 打印数组值
void IntArray::outArray()
{
    std::cout << "=> outArray()" << std::endl;

    for (int i = 0; i < m_length; i++)
    {
        std::cout << "Array[" << i << "]=" << m_pointer[i] << " ";
    }

    std::cout << std::endl;
}

// 返回自身对象来进行后续操作，避免直接对指针对象操作
IntArray &IntArray::self()
{
    return *this;
}

// 析构函数中释放内存资源
void IntArray::free()
{
    std::cout << "=> free()" << std::endl;

    delete[] m_pointer;
}
