#include <stdio.h>

int main(void)
{
    char *s1 = "Olá";
    char s2[] = "Olá";

    printf("s1 as string:   %s\n", s1);
    printf("s2 as string:   %s\n", s2);

    printf("s1 as address:  %p\n", (void*)s1);
    printf("s2 as address:  %p\n", (void*)s2);

    printf("&s1 as address: %p\n", &s1);
    printf("&s2 as address: %p\n", &s2);

    printf("s1 as address:  %p\n", s1);
    printf("s2 as address:  %p\n", s2);

    printf("s2+1:           %p\n", (void*)(s2 + 1));
    printf("&s2+1:          %p\n", (void*)(&s2 + 1));

    s2[0] = 'x';
    s1[0] = 'x';

    printf("s1 as string:   %s\n", s1);
    printf("s2 as string:   %s\n", s2);

}
