// https://stackoverflow.com/a/17850402/5209556

#include <stdio.h>

extern void *__libc_malloc(size_t size);

void*
malloc (size_t size)
{
    void *p = __libc_malloc(size);
    fprintf(stderr, "malloc(%zu) = %p\n", size, p);
    return p;
}
