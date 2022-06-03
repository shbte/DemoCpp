#include <iostream>

int main()
{
    printf("5/3=%d\n", 5/3);
    // 因为编译器把int类型数据当成了doule数据进行存储，0.(1022个0)1(51个0)1
    printf("3/2=%f\n", 1);
    // printf("3/2=%.1024f\n", 1/(2 >> 1023) + 1/(2 >> 1075));
    printf("3/2=%f\n", 1.5);

    std::cout << "3/2=" << 3/2 << std::endl; 

    printf("main=%p\n", main);

    return 0;
}

/*
==>
printf("3/2=%f\n", 1);

0000 0000 0000 0000 0000 .... 0001
+000 0000 0000 0000 0000 .... 0001
1.0000 0000 .... 0001 * 2^(000 0000 0000 - 011 1111 1111)
1.0000 .... 0001 * 2^(-1023)
1.(51个0)1  * 2^(-1023)
0.(1022个0)1(51个0)1
1/(2^1023) + 1/(2^1075)

<==
*/