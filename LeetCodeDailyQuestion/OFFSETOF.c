#include <stdio.h>

struct S
{
    char c;
    int a;
    double d;
};

#define   OFFSETOF(type, mem)    ((size_t) & (((type *)0)->mem))

int main()
{
    struct S s;
    printf("c相较于起始位置的偏移量为:%zd\n", OFFSETOF(struct S, c));
    printf("a相较于起始位置的偏移量为:%zd\n", OFFSETOF(struct S, a));
    printf("d相较于起始位置的偏移量为:%zd\n", OFFSETOF(struct S, d));
    return 0;
}
