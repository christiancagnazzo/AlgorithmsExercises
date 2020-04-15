CFLAGS=-g -O0 -I include -I Resources/C/Unity/

all: bin/test bin/app

clean:
	$(RM) -rf build/* 
	$(RM) -rf bin/*

build/hash_map.o: include/hash_map.h src/hash_map.c
	$(CC) $(CFLAGS) -c src/hash_map.c -o build/hash_map.o

bin/test: build/hash_map.o test/hash_map_test.c
	$(CC) $(CFLAGS) test/hash_map_test.c build/hash_map.o Resources/C/Unity/unity.c -o bin/test

bin/app: build/hash_map.o hash_map_app/hash_map_app.c
	$(CC) $(CFLAGS) hash_map_app/hash_map_app.c build/hash_map.o -o bin/app
