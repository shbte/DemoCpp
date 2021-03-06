#### 结构体 && 类 : 00

```
struct和class唯一区别为
    struct的默认访问级别为public
    class的默认访问级别为private
```

#### 对象声明、定义、无参构造函数、拷贝构造函数 : 01、02

```
对象的定义和对象的声明是不同的
    对象的定义：申请对象的空间并调用构造函数
    对象的声明：告诉编译器存在这样一个对象

无参构造函数
    没有参数的构造函数
    当类中没有定义构造函数时，编译器默认提供一个无参构造函数，并且其函数体为空

拷贝构造函数
    参数为const class_name&的构造函数
    当类中没有定义拷贝构造函数时，编译器默认提供一个拷贝构造函数，简单的进行成员的值复制
    编译器提供的拷贝构造函数只进行浅拷贝
        浅拷贝：拷贝后对象的物理状态相同(两个对象的new指针指向同一个地址，可能会导致同一地址会被释放两次)
        深拷贝：拷贝后对象的逻辑状态相同
```

#### 初始化成员列表、对象的构造顺序 : 03

```
C++中提供了初始化列表对成员变量进行初始化，初始化列表先于构造函数执行

语法规则
    ClassName::ClassName() : mv(v1), m2(v1, v2), m3(v3)
    {
        //some other initialize operation
    }

初始化与赋值不同
    初始化：对正在创建的对象进行初值设置
    赋值：对已经存在的对象进行值设置

全局对象的构造顺序是不确定的(不同编译平台不同)，所以在开发中要尽量避免全局对象间的相互依赖
直接调用构造函数时会产生一个临时对象，该临时对象的有效范围只有这行，下行执行析构函数进行销毁

注意事项：
    成员的初始化顺序与成员的声明顺序相同
    成员的初始化顺序与初始化列表中的位置无关
    初始化列表先于构造函数的函数体执行
```

#### 析构函数 : 04

```
C++的类中可以定义一个特殊的清理函数
    这个特殊的清理函数叫做析构函数
    析构函数的功能与构造函数相反

定义：~ClassName()
    析构函数没有参数也没有返回值类型声明
    析构函数在对象销毁时自动被调用

析构函数的定义准则
    当类中自定义了构造函数，并且构造函数中使用了系统资源(如:内存申请，文件打开等)，则需要自定义析构函数

析构函数的执行顺序和构造函数的顺序相反
    有delete，优先delete
```

#### 补充

```
const关键字能够修饰对象
const修饰的对象为只读对象
只读对象的成员变量不允许被改变
只读对象是编译阶段的概念，运行时无效
C++中的const成员函数
    const对象只能调用const的成员函数
    const成员函数中只能调用const成员函数
    const成员函数中不能直接改写成员变量的值

所有的对象共享类的成员函数，隐藏的this指针用于表示当前对象
```

| |静态成员函数|普通成员函数|
|:---:|:---:|:---:|
|所有对象共享|Yes|Yes|
|隐含this指针|No|Yes|
|访问普通成员变量(函数)|No|Yes|
|访问静态成员变量(函数)|Yes|Yes|
|通过类名直接调用|Yes|No|
|通过对象名直接调用|Yes|Yes|
