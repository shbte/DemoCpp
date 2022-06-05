#include <iostream>

/*
==>
自定义类的左移操作符重载时，返回的是引用对象，以达到连续引用的目的
<==
*/
const char endl = '\n';

class Console
{
private:
    int i;

public:
    Console &operator<<(const int i) // 返回的是引用对象，以达到连续引用的目的
    {

        printf("%d", i);

        return *this;
    }

    Console &operator<<(const char c)
    {
        printf("%c", c);

        return *this;
    }

    Console &operator<<(const char *s)
    {
        printf("%s", s);

        return *this;
    }

    Console &operator<<(const double d)
    {
        printf("%f", d);

        return *this;
    }
};

int main()
{

    Console con;

    con << 1 << 'a' << "Hello " << 34.09 << endl;

    return 0;
}