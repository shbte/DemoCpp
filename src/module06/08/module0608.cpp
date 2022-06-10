#include <iostream>

using namespace std;

/*
==>

<==
*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "virtual.h"

#ifdef __cplusplus
}
#endif

/*
==>

虚函数：
    p => (具体对象 | VPTR) => (VTABLE | void (*pADD)(int value)) => (0xFF010203)

编译执行命令：
    gcc -c ./virtual.c -o ./virtual.o
    g++ ./module0608.cpp ./virtual.o
    ./a.out

log：
Demo::mi = 1, mj = 2
Device::mi = 1, mj = 2, mk = 3

Demo.value + 8 = 
Demo_Add(Demo *pThis, int value)
Virtual_Demo_Add(Demo *pThis, int value)
11
Device.value + 8 = 
Device_Add(Device *pThis, int value)
Virtual_Device_Add(Device *pThis, int value)
14

run(ptr_demo, 8) = 
Demo_Add(Demo *pThis, int value)
Virtual_Demo_Add(Demo *pThis, int value)
11
run(ptr_device, 8) = 
Demo_Add(Demo *pThis, int value)    => 子类的父类对象调用虚函数接口，进入子类函数
Virtual_Device_Add(Device *pThis, int value)
14

free::this=0x562c261e1eb0
free::this=0x562c261e1ed0
<==
*/
int run(void *p, int value)
{
    int ret = Demo_Add(p, value);
    return ret;
}

int main()
{
    Demo *ptr_demo = Demo_Create(1, 2);
    Device *ptr_device = Device_Create(1, 2, 3);

    cout << "Demo::mi = " << Demo_GetI(ptr_demo)
         << ", mj = " << Demo_GetJ(ptr_demo) << endl;
    cout << "Device::mi = " << Demo_GetI(ptr_device)
         << ", mj = " << Demo_GetJ(ptr_device)
         << ", mk = " << Device_GetK(ptr_device) << endl
         << endl;

    int value = 8;

    cout << "Demo.value + " << value << " = " << Demo_Add(ptr_demo, value) << endl;
    cout << "Device.value + " << value << " = " << Device_Add(ptr_device, value) << endl
         << endl;

    // 多态体现：不同的对象调用同一方法，返回不同的结果
    cout << "run(ptr_demo, " << value << ") = " << run(ptr_demo, value) << endl;
    cout << "run(ptr_device, " << value << ") = " << run(ptr_device, value) << endl
         << endl;

    Free(ptr_demo);
    Free(ptr_device);

    return 0;
}