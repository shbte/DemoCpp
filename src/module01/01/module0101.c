#include <stdio.h>

/*
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$ gcc ./module0101.c
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$ ./a.out
a = 2, b = 1
ubuntu@ubuntu:~/Desktop/VSCode/PracticeCPP/src/module01/01$
*/
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a = 1;
    int b = 2;

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}