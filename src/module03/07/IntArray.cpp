#include <iostream>

#include "IntArray.h"

IntArray::IntArray(int len)
{
    std::cout << "=> IntArray" << std::endl;

    m_length = len;
}

// 深拷贝实现
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

bool IntArray::construct()
{
    std::cout << "=> construct" << std::endl;

    bool ret = false;
    m_pointer = new int[m_length];

    for (int i = 0; i < m_length; i++)
    {
        m_pointer[i] = i;
    }

    ret = true;

    return ret;
}

IntArray *IntArray::NewInstance(int len)
{
    std::cout << "=> NewInstance" << std::endl;

    IntArray *intAObj = new IntArray(len);

    if (!(intAObj && (intAObj->construct())))
    {
        delete intAObj;
        intAObj = NULL;
    }

    return intAObj;
}

int IntArray::getLength()
{
    return m_length;
}

bool IntArray::getValue(int index, int &value)
{
    // std::cout << "=> getValue(" << index << ")" << std::endl;

    bool ret = (0 <= index) && (index < getLength());

    if (ret)
    {
        value = m_pointer[index];
    }

    return ret;
}

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

void IntArray::outArray()
{
    std::cout << "=> outArray()" << std::endl;

    for (int i = 0; i < m_length; i++)
    {
        std::cout << "Array[" << i << "]=" << m_pointer[i] << std::endl;
    }
}

void IntArray::free()
{
    std::cout << "=> free()" << std::endl;

    delete[] m_pointer;
}
