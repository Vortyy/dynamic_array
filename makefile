CC = clang
CFLAGS = -g

shared_lib: build_lib
	$(CC) -shared build/dynamic_array.o -o lib/libdynamic_array.so 

# generates static library
lib_a: build_lib
	ar rcs lib/libdynamic_array.a build/dynamic_array.o

build_lib :
	$(CC) $(CFLAGS) -c src/dynamic_array.c -o build/dynamic_array.o -fPIC

# interesting to note that you can specific which format you want link you're lib by -l:filename.a (or .so)
# link : https://stackoverflow.com/questions/6578484/telling-gcc-directly-to-link-a-library-statically
static.exe :
	$(CC) src/main.c -L./lib -l:libdynamic_array.a -o da_static 
	ldd da_static

#fun part makefile process each command in separated shell then export never affect the current shell
#So important part to dynamic library is to get an access to them at running time by specifying an 
# -- env var LD_LIBRARY_PATH
shared.exe :
	$(CC) src/main.c -L./lib -ldynamic_array -o da_shared
	ldd da_shared

clean : 
	rm -rf da_shared da_static
