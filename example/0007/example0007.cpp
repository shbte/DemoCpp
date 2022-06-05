#include <iostream>

using namespace std;

void func1()
{
    string s = "12345";
    const char *p = s.c_str();

    s.append("asdfg"); // s追加新字符串时，s指针重新指向了新生成的字符串，s的地址改变，p的地址不变

    // p(value)=1, p(address)=12345asdfg
    cout << "p(value)=" << *p << ", p(address)=" << p << endl;
    // s(value)=12345asdfg, s(address)=0x7fff33521ea0
    cout << "s(value)=" << s << ", s(address)=" << &s << endl;
}

void func2()
{
    const char *p = "12345";
    string s = "";

    s.reserve(10); // 给s分配10个空间

    for (int i = 0; i < 5; i++)
    {
        s[i] = p[i];
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "p[" << i << "]=" << p[i] << endl; // 值正常
        cout << "s[" << i << "]=" << s[i] << endl; // 值正常
    }

    // string类中有专门的成员变量存储string对象长度，上面赋值操作时并没有更新string对象长度，所以s长度为0(s is empty)
    cout << "s(size)=" << s.length() << endl; // s(size)=0
}

int main()
{

    func1();
    func2();

    return 0;
}