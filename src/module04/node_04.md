#### 友元 : 00

```
友元是为了兼顾C语言的高效而诞生的
友元直接破坏了面向对象的封装性
友元关系不具备传递性
类的友元可以是其它类的成员函数
类的友元可以是某个完整的类
```

#### 函数重载 : 01

```
函数的重载需要判定作用域，不同作用域构不成函数重载
```

#### 操作符重载 : 02、03

```
重载操作符，可使用operator关键字
    Type operator sign(const Type& p1, const Type& p2)
    sign为操作符：+、-、*、/

操作符重载的本质是通过函数扩展操作符功能
operator关键字是实现操作符重载的关键
操作符重载遵循相同的函数重载规则
全局函数和成员函数都可以实现对操作符的重载
操作符重载不能改变原操作符的优先级
操作符重载不能改变操作符的个数
操作符重载不应改变操作符的原有语义
C++规定赋值操作符(=)只能重载为成员函数，因为编译器默认实现了类赋值操作(=)，全局函数因为优先级的问题而先执行成员函数
自定义类的左移操作符重载时，返回的是引用对象，以达到连续引用的目的
```

#### string类型 : 04、

```
=====
typedef basic_string<char> string;
template <typename T>
struct basic_string {
    char* begin_;
    size_t size_;
    union {
        size_t capacity_;
        char sso_buffer[16];
    };
};
sizeof(string) = 32 = 8 + 8 + 16;
=====

string对象存储的内容大小与其所占的空间（栈空间）是没有关系的，利用这点获取string类型数组的长度
    string对象存储的是内容的地址

使用宏定义完成字符串和数字之间的相互转化(#include <sstream>)
    #define TO_NUMBER(s, n) (istringstream(s) >> n)
    #define TO_STRING(n) ((ostringstream() << n).str())

下面方式得不到string类型数组的长度，得到的是第一个元素的长度
    s->size();   // ==> s[0].size() ==> 11
    s->length(); // 同上
```

#### 数组操作符重载 : 05

```
判断字符串中数字出现的次数函数：isdigit
需要使用对象时，返回类型需要加上&
    type &operator[]()
```

#### 重载函数调用操作符 : 06

```
函数调用操作符(())
    只能通过类的成员函数重载，因为需要绑定该类对象的行为
    可以定义不同参数的多个重载函数
    函数对象用于在工程中取代函数指针
```

#### 拷贝构造函数 : 07、08

```
编译器为每个类默认重载了赋值操作符，但仅完成了浅拷贝
    浅拷贝会导致两个对象内的指针指向统一地址，释放时会释放同一地址两次，从而发生错误

当需要进行深拷贝时必须重载赋值操作符
赋值操作符与拷贝构造函数有相同的存在意义

编译器为类默认提供的函数
    构造函数
        无参构造函数(存在其它构造函数时，编译器将不再默认提供无参构造函数)
        拷贝构造函数(存在其它拷贝构造函数时，编译器将不再默认提供拷贝构造函数)
    赋值操作符
    析构函数

当对象内指针指向了外部资源(使用了外部资源)时，必须要进行重载赋值操作符达到深拷贝的目的
```

```
多了&符号，不是调用拷贝构造函数的形式，而是array0的别名
    // IntArray &array1(array0);
```
