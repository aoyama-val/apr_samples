all: a.out libmalloc.so

a.out: main.o
	gcc -lm -lapr-1 -laprutil-1 -L/usr/local/apr/lib $< -o $@

libmalloc.so: malloc.c
	gcc -shared -fPIC $^ -o $@

.c.o:
	gcc -g -O0 -c -D_LARGEFILE64_SOURCE -I/usr/local/apr/include/apr-1 $< -o $@

run: a.out
	@LD_PRELOAD=./libmalloc.so LD_LIBRARY_PATH=/usr/local/apr/lib ./a.out

debug: a.out
	@LD_LIBRARY_PATH="/usr/local/apr/lib" gdb ./a.out

clean:
	rm -rf *.o a.out libmalloc.so
