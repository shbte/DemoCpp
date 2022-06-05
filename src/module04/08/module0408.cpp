#include <iostream>

#include "IntArray.h"

int main()
{
    IntArray &array0 = IntArray::NewInstance(5);

    // 多了&符号，不是调用拷贝构造函数的形式，而是array0的别名，放开最后注释以验证
    // IntArray &array1(array0);
    // IntArray &array2 = array0;

    // 自定义拷贝构造函数，进行深拷贝
    IntArray array1(array0);
    IntArray array2 = array0;

    IntArray &array3 = IntArray::NewInstance(10);

    std::cout << std::endl;
    std::cout << "a3::m_length=" << array3.getLength() << ", m_pointer(value)=" << std::endl;
    array3.outArray();
    std::cout << "a3::m_pointer(address)=" << array3.getAddress() << std::endl;

    array3 = array0; // 自定义赋值操作符，深拷贝

    std::cout << std::endl;
    std::cout << "a0::m_length=" << array0.getLength() << ", m_pointer(value)=" << std::endl;
    array0.outArray();
    std::cout << "a0::m_pointer(address)=" << array0.getAddress() << std::endl;

    std::cout << std::endl;
    std::cout << "a3::m_length=" << array3.getLength() << ", m_pointer(value)=" << std::endl;
    array3.outArray();
    std::cout << "a3::m_pointer(address)=" << array3.getAddress() << std::endl;

    std::cout << std::endl;
    std::cout << "a1::m_length=" << array1.getLength() << ", m_pointer(value)=" << std::endl;
    array1.outArray();
    std::cout << "a1::m_pointer(address)=" << array1.getAddress() << std::endl;

    std::cout << std::endl;
    std::cout << "a2::m_length=" << array2.getLength() << ", m_pointer(value)=" << std::endl;
    array2.outArray();
    std::cout << "a2::m_pointer(address)=" << array2.getAddress() << std::endl;

    /*1和2随着0改变而改变，验证了(IntArray &array1(array0);IntArray &array2 = array0;)为别名
    array0 = IntArray::NewInstance(7);

    std::cout << std::endl;
    std::cout << "a0::m_length=" << array0.getLength() << ", m_pointer(value)=" << std::endl;
    array0.outArray();
    std::cout << "a0::m_pointer(address)=" << array0.getAddress() << std::endl;

    std::cout << std::endl;
    std::cout << "a1::m_length=" << array1.getLength() << ", m_pointer(value)=" << std::endl;
    array1.outArray();
    std::cout << "a1::m_pointer(address)=" << array1.getAddress() << std::endl;

    std::cout << std::endl;
    std::cout << "a2::m_length=" << array2.getLength() << ", m_pointer(value)=" << std::endl;
    array2.outArray();
    std::cout << "a2::m_pointer(address)=" << array2.getAddress() << std::endl;
    */

    return 0;
}