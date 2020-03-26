CFLAGS = -I include -I Resources/C/Unity/

all: bin/test

clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*

build/order_lib.o: src/order_lib.c include/order_lib.h 
	$(CC) $(CFLAGS) -c src/order_lib.c -o build/order_lib.o

bin/test: test/test_insertion_sort.c build/order_lib.o include/order_lib.h
	$(CC) $(CFLAGS) test/test_insertion_sort.c  build/order_lib.o Resources/C/Unity/unity.c -o bin/test 