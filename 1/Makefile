CFLAGS=-g3 -O0 -W -Wall -Wno-unused-parameter
APR_DIR=/usr/local/apr
APR_INC_DIR=$(APR_DIR)/include/apr-1
APR_LIB_DIR=$(APR_DIR)/lib

a.out: main.o
	gcc -lm -lapr-1 -L$(APR_LIB_DIR) $< -o $@

.c.o:
	gcc $(CFLAGS) -c -D_LARGEFILE64_SOURCE -I$(APR_INC_DIR) $< -o $@

run: a.out
	@LD_LIBRARY_PATH="$(APR_LIB_DIR)" ./a.out

debug: a.out
	@LD_LIBRARY_PATH="$(APR_LIB_DIR)" gdb ./a.out

clean:
	rm -rf *.o a.out
