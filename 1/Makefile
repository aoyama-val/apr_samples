a.out: main.o
	gcc -m32 -lapr-1 -laprutil-1 -L/usr/local/apr/lib $^ -o $@

.c.o:
	gcc -c -m32 -D_LARGEFILE64_SOURCE -I/usr/local/apr/include/apr-1 $< -o $@

run: a.out
	@LD_LIBRARY_PATH="/usr/local/apr/lib" ./a.out

clean:
	rm -rf *.o a.out
