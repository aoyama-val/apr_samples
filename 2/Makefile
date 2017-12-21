CFLAGS=-g3 -O0
APR_DIR=/usr/local/apr
APR_INC_DIR=$(APR_DIR)/include/apr-1
APR_LIB_DIR=$(APR_DIR)/lib

all: a.out libmalloc.so

a.out: main.o
	gcc -lm -lapr-1 -L$(APR_LIB_DIR) $< -o $@

libmalloc.so: malloc.c
	gcc $(CFLAGS) -shared -fPIC $^ -o $@

.c.o:
	gcc $(CFLAGS) -c -D_LARGEFILE64_SOURCE -I$(APR_INC_DIR) $< -o $@

run: all
	@LD_PRELOAD=./libmalloc.so LD_LIBRARY_PATH=$(APR_LIB_DIR) ./a.out

debug: all
	@LD_LIBRARY_PATH="$(APR_LIB_DIR)" gdb ./a.out

clean:
	rm -rf *.o a.out libmalloc.so
