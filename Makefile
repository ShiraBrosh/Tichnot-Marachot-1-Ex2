
CFLAGS = -Wall -g
CC = gcc
AR = ar
FP = fPIC

all: mains

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -$(FP) -c my_mat.c -o my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -$(FP) -c my_graph.c -o my_graph.o

libmy_mat.a: my_graph.o 
	$(AR) -rcs libmy_mat.a my_mat.o 

mains: my_graph.o libmy_mat.a
	$(CC) -o connections my_graph.o libmy_mat.a $(CFLAGS)

.PHONY: clean all

clean: 
	rm -f *.o *.a  mains
