#include <stdio.h>
#include <stdlib.h>
#include <apr.h>
#include <apr_pools.h>

int main(int argc, char *argv[])
{
    apr_pool_t *pool;

    printf("main\n");
    apr_initialize();

    apr_pool_create(&pool, NULL);

    char* s1 = apr_pstrdup(pool, "hoge");
    char* s2 = apr_pstrdup(pool, "moge");

    int n = apr_strnatcmp(s1, s2);
    printf("n = %d\n", n);

    apr_pool_destroy(pool);

    apr_terminate();

    return 0;
}
