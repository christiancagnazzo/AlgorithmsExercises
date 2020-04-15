CFLAGS=-g -O0 -I include -I Resources/C/Unity/

all:

clean:
	rm -rf build/*

build/hash_map.o: include/hash_map.h src/hash_map.c
	$(CC) $(CFLAGS) -c src/hash_map.c -o build/hash_map.o