#include <iostream>

int main()
{
    int i = 5;
    do
    {
        switch (i % 2)
        {
        case 0:
            i--;
            // 这里是退出switch，执行下面i--(19行)
            break;
        case 1:
            i--;
            // 这里是退出while循环
            continue;
        }
        i--;
        std::cout << i;
    } while (i > 0);
    std::cout << std::endl;
}