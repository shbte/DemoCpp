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
<==
*/
int main()
{
    Demo *ptr_demo = Demo_Create(1, 2);
    Device *ptr_device = Device_Create(1, 2, 3);

    cout << "Demo::mi=" << Demo_GetI(ptr_demo)
         << ", mj=" << Demo_GetJ(ptr_demo) << endl;
    cout << "Device::mi=" << Demo_GetI(ptr_device)
         << ", mj=" << Demo_GetJ(ptr_device)
         << ", mk=" << Device_GetK(ptr_device) << endl << endl;

    cout << "Demo.value + 4 = " << Demo_Add(ptr_demo, 4) << endl;
    cout << "Device.value + 4 = " << Device_Add(ptr_device, 4) << endl << endl;

    Free(ptr_demo);
    Free(ptr_device);

    return 0;
}