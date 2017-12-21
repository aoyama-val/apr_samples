#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <apr.h>
#include <apr_pools.h>
#include <apr_strings.h>

int main(int argc, char *argv[])
{
    apr_pool_t *pool;

    printf("main\n");
    apr_initialize();

    apr_pool_create(&pool, NULL);

    for (int i = 0; i < 20; i++) {
        size_t size = (size_t)pow(2, i);
        fprintf(stderr, "calling apr_palloc(%zu)\n", size);
        apr_palloc(pool, size);
    }

    apr_pool_destroy(pool);

    apr_terminate();

    return 0;
}
