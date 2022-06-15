#include <stdio.h>

struct point
{
    int x;
    int y;
};

void foo(struct point p[])
{
    // 把5 ==> 6 
    printf("%d %d\n", p->x, ++p->x); // 2 2
    // printf("%d %d\n", p->x, (++p)->x); // 3 3
    // printf("%d %d\n", p->x, ++(p->x)); // 2 2
}

int main()
{
    // struct point p[] = {1, 2, 3, 4, 5};
    struct point p[] = {5, 4, 3, 2, 1};
    printf("%d %d\n", p->x, p->y); // 5 4

    printf("%d %d\n", p[1].x, p[1].y);

    foo(p);
    printf("%d %d\n", p->x, p->y); // 6 4

    return 0;
}