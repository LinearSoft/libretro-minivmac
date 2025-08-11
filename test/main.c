#include <stdio.h>

extern void foo(void);

int main(void)
{
   puts("This is a shared library test...");
   foo();
}

// gcc -static -o run main.o fooa.o susan.o
// gcc -c main.c fooa.c foob.c