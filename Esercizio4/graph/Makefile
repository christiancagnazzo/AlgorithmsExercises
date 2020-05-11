CFLAGS = -I include 

all: bin/main

clean:
	$(RM) -rf bin/*
	$(RM) -rf build/*

build/graph.o: src/graph.c include/graph.h 
	$(CC) $(CFLAGS) -c src/graph.c -o build/graph.o

bin/main: app/main.c build/graph.o include/graph.h
	$(CC) $(CFLAGS) app/main.c build/graph.o -o bin/app