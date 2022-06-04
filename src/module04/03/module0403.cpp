#include <iostream>

const char endl = '\n';

class Console
{
private:
    int i;

public:
    Console &operator<<(const int i)
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