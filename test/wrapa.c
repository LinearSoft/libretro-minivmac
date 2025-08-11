#include <stdio.h>

extern void foo(void);

void wrap(void)
{
    puts("Hello, I am library wrapper for BBBB");
    foo();
}

void bubba(void)
{
   puts("Hello, I am bubba BBBB");
}