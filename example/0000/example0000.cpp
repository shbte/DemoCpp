#include <stdio.h>
// #include <iostream>

void test01()
{
    int i = 7;

    while (i--)
    {
        // 6 5 4 3 2 1 0
        printf("%d ", i);
        // std::cout << i << std::endl;
    }

    puts("");

    for (i; i < 10; i++)
    {
        // -1 : 说明i=0后，又进行了--
        // -1 0 1 2 3 4 5 6 7 8 9
        printf("%d ", i);
    }

    puts("");
}

void test02()
{
    int i = 7;

    while (--i)
    {
        // 6 5 4 3 2 1
        printf("%d ", i);
    }

    puts("");

    for (i; i < 10; i++)
    {
        // 0 1 2 3 4 5 6 7 8 9
        printf("%d ", i);
    }

    puts("");
}

int main()
{
    test01();

    test02();
}
