#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <apr.h>
#include <apr_pools.h>
#include <apr_strings.h>

#define ARR_LEN(a) (sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[])
{
    apr_pool_t *pool;

    fprintf(stderr, "main\n");
    apr_initialize();

    apr_pool_create(&pool, NULL);

    size_t sizes[] = {
        10,
        10,
        8000,
        12000,
        16000,
        20000,
        10,
        100,
        1000,
        2000,
    };

    for (int i = 0; i < (int)ARR_LEN(sizes); i++) {
        size_t size = sizes[i];
        fprintf(stderr, "\ncalling apr_palloc(%zu)\n", size);
        apr_palloc(pool, size);
    }

    fprintf(stderr, "clear\n");
    apr_pool_destroy(pool);

    apr_pool_create(&pool, NULL);

    size_t sizes2[] = {
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
        400,
    };

    for (int i = 0; i < (int)ARR_LEN(sizes2); i++) {
        size_t size = sizes2[i];
        fprintf(stderr, "\ncalling apr_palloc(%zu)\n", size);
        apr_palloc(pool, size);
    }
    //for (int i = 0; i < 100; i++) {
        //size_t size = 500;
        //fprintf(stderr, "\ncalling apr_palloc(%zu)\n", size);
        //apr_palloc(pool, size);
    //}

    apr_pool_destroy(pool);

    apr_terminate();

    return 0;
}
