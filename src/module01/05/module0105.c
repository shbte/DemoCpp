#include <stdio.h>

// C语言，不允许出现默认参数
// int mul(int x = 0);

int main()
{
    printf("%d\n", mul(2));
}

int mul(int x)
{
    return x * x;
}