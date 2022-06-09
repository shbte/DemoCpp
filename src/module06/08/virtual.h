#ifndef _VIRTUAL_H_
#define _VIRTUAL_H_

// 面向对象的三大特性：封装、继承、多态

// 封装(void保证外界无法通过具体对象访问)，DemoClass和Device不在头文件中定义，所以访问不到
typedef void Demo;
typedef void Device;

// 父类方法
Demo *Demo_Create(int i, int j);
int Demo_GetI(Demo *pThis); // pThis是具体对象指针，在C++中，有隐式this指针指向具体指针
int Demo_GetJ(Demo *pThis);
int Demo_Add(Demo *pThis, int value);

// 子类方法
Device *Device_Create(int i, int j, int k);
int Device_GetK(Device *pThis);
int Device_Add(Device *pThis, int value);

void Free(void *pThis);

#endif