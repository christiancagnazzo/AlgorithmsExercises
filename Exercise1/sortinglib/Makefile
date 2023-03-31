CFLAGS = -I include -I Resources/C/Unity/

all: bin/test_insertion_sort bin/test_quick_sort bin/sorting_lib_app

clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*

build/sorting_lib.o: src/sorting_lib.c include/sorting_lib.h 
	$(CC) $(CFLAGS) -c src/sorting_lib.c -o build/sorting_lib.o

bin/test_insertion_sort: test/test_insertion_sort.c build/sorting_lib.o include/sorting_lib.h
	$(CC) $(CFLAGS) test/test_insertion_sort.c  build/sorting_lib.o Resources/C/Unity/unity.c -o bin/test_insertion_sort

bin/test_quick_sort: test/test_quick_sort.c build/sorting_lib.o include/sorting_lib.h
	$(CC) $(CFLAGS) test/test_quick_sort.c  build/sorting_lib.o Resources/C/Unity/unity.c -o bin/test_quick_sort

bin/sorting_lib_app: sorting_lib_app/sorting_lib_app.c build/sorting_lib.o include/sorting_lib.h
	$(CC) $(CFLAGS) sorting_lib_app/sorting_lib_app.c build/sorting_lib.o -o bin/app