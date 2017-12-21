// https://stackoverflow.com/a/17850402/5209556

#include <stdio.h>

extern void *__libc_malloc(size_t size);

void*
malloc (size_t size)
{
    void *caller = __builtin_return_address(0);
    void *p = __libc_malloc(size);
    fprintf(stderr, "malloc(%d) = %p\n", size, p);
    return p;
}
